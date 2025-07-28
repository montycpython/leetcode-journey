impl Solution {
    pub fn maximum_gain(s: String, x: i32, y: i32) -> i32 {
        // Core logic for removing a specific pair and accumulating points
        fn remove(s: &mut [u8], first: u8, second: u8, score: i32) -> (usize, i32) {
            let mut write = 0;
            let mut total = 0;

            for i in 0..s.len() {
                let c = s[i];
                if write > 0 && s[write - 1] == first && c == second {
                    write -= 1;
                    total += score;
                } else {
                    s[write] = c;
                    write += 1;
                }
            }

            (write, total)
        }

        let mut bytes = s.into_bytes();

        // Process in the most profitable order first
        let total_score = if x >= y {
            let (len, score1) = remove(&mut bytes, b'a', b'b', x);
            let (_, score2) = remove(&mut bytes[..len], b'b', b'a', y);
            score1 + score2
        } else {
            let (len, score1) = remove(&mut bytes, b'b', b'a', y);
            let (_, score2) = remove(&mut bytes[..len], b'a', b'b', x);
            score1 + score2
        };

        total_score
    }
}
