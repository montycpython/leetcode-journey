import hashlib
import struct
import time
import threading

# Sample transactions
transactions = [
    "tx1: Alice pays Bob 5 BTC",
    "tx2: Bob pays Charlie 2 BTC",
    "tx3: Charlie pays Dave 1 BTC",
    "tx4: Dave pays Eve 0.5 BTC"
]

def double_sha256(data: bytes) -> bytes:
    return hashlib.sha256(hashlib.sha256(data).digest()).digest()

def compute_merkle_root(tx_list):
    hashes = [double_sha256(tx.encode()) for tx in tx_list]
    while len(hashes) > 1:
        if len(hashes) % 2 != 0:
            hashes.append(hashes[-1])
        new_hashes = []
        for i in range(0, len(hashes), 2):
            new_hashes.append(double_sha256(hashes[i] + hashes[i+1]))
        hashes = new_hashes
    return hashes[0]

def serialize_header(version, prev_hash, merkle_root, timestamp, bits, nonce):
    return (
        struct.pack("<L", version) +
        prev_hash[::-1] +
        merkle_root[::-1] +
        struct.pack("<L", timestamp) +
        struct.pack("<L", bits) +
        struct.pack("<L", nonce)
    )

def deserialize_header(header_bytes):
    version = struct.unpack("<L", header_bytes[0:4])[0]
    prev_hash = header_bytes[4:36][::-1].hex()
    merkle_root = header_bytes[36:68][::-1].hex()
    timestamp = struct.unpack("<L", header_bytes[68:72])[0]
    bits = struct.unpack("<L", header_bytes[72:76])[0]
    nonce = struct.unpack("<L", header_bytes[76:80])[0]
    return {
        "version": version,
        "prev_hash": prev_hash,
        "merkle_root": merkle_root,
        "timestamp": timestamp,
        "bits": bits,
        "nonce": nonce
    }

# Multithreaded mining
def mine_worker(start_nonce, step, version, prev_hash, merkle_root, timestamp, bits, difficulty_prefix, stop_event, result):
    nonce = start_nonce
    while not stop_event.is_set():
        header = serialize_header(version, prev_hash, merkle_root, timestamp, bits, nonce)
        block_hash = double_sha256(header)[::-1]
        if block_hash.hex().startswith(difficulty_prefix):
            result["nonce"] = nonce
            result["hash"] = block_hash
            result["header"] = header
            stop_event.set()
            return
        nonce += step

def mine_block_multithreaded(version, prev_hash, merkle_root, timestamp, bits, difficulty_prefix="0000", num_threads=4):
    stop_event = threading.Event()
    result = {}
    threads = []

    for i in range(num_threads):
        t = threading.Thread(
            target=mine_worker,
            args=(i, num_threads, version, prev_hash, merkle_root, timestamp, bits, difficulty_prefix, stop_event, result)
        )
        t.start()
        threads.append(t)

    for t in threads:
        t.join()

    return result["nonce"], result["hash"], result["header"]

# Block header fields
version = 1
prev_block_hash = bytes.fromhex("00" * 32)
merkle_root = compute_merkle_root(transactions)
timestamp = int(time.time())
bits = 0x1d00ffff

# Mine the block using multithreading
nonce, block_hash, header = mine_block_multithreaded(version, prev_block_hash, merkle_root, timestamp, bits, difficulty_prefix="0000", num_threads=8)

# Output
print("🚀 Valid Nonce Found:", nonce)
print("🔒 Block Hash:", block_hash.hex())
print("📦 Deserialized Header:", deserialize_header(header))
