use std::collections::HashSet;

impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let mut seen = HashSet::new();
        let mut sums = HashSet::new();
        let mut best = i32::MIN;

        sums.insert(0); // Start with empty subset

        for &num in &nums {
            if seen.contains(&num) {
                continue; // Skip duplicates
            }
            seen.insert(num);

            let mut new_sums = HashSet::new();
            for &s in &sums {
                let candidate = s + num;
                best = best.max(candidate);
                new_sums.insert(candidate);
            }
            sums.extend(new_sums);
        }

        best
    }
}
