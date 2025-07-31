use std::collections::HashSet;

impl Solution {
    pub fn subarray_bitwise_o_rs(arr: Vec<i32>) -> i32 {
        let mut result: HashSet<i32> = HashSet::new();
        let mut curr: HashSet<i32> = HashSet::new();

        for &num in &arr {
            let mut next: HashSet<i32> = HashSet::new();
            next.insert(num);

            for &val in &curr {
                next.insert(val | num);
            }

            curr = next;
            result.extend(&curr);
        }

        result.len() as i32
    }
}
