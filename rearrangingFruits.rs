use std::collections::BTreeMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let mut freq = BTreeMap::new();
        let mut min_val = i32::MAX;

        for &x in &basket1 {
            *freq.entry(x).or_insert(0) += 1;
            min_val = min_val.min(x);
        }

        for &x in &basket2 {
            *freq.entry(x).or_insert(0) -= 1;
            min_val = min_val.min(x);
        }

        let mut excess = Vec::new();

        for (&val, &delta) in freq.iter() {
            if delta % 2 != 0 {
                return -1;
            }
            let count = (delta as i32).abs() as usize / 2;
            for _ in 0..count {
                excess.push(val);
            }
        }

        let swaps = excess.len() / 2;
        let mut cost = 0i64;

        for i in 0..swaps {
            let direct = excess[i];
            let via_min = 2 * min_val;
            cost += direct.min(via_min) as i64;
        }

        cost
    }
}
