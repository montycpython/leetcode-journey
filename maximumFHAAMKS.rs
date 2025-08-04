impl Solution {
    pub fn max_total_fruits(fruits: Vec<Vec<i32>>, start_pos: i32, k: i32) -> i32 {
        let n = fruits.len();
        let mut max_fruits = 0;
        let mut total = 0;
        let mut left = 0;

        for right in 0..n {
            total += fruits[right][1];

            while left <= right {
                let left_pos = fruits[left][0];
                let right_pos = fruits[right][0];

                let steps_left_first = (start_pos - left_pos).abs() + (right_pos - left_pos);
                let steps_right_first = (right_pos - start_pos).abs() + (right_pos - left_pos);
                let min_steps = steps_left_first.min(steps_right_first);

                if min_steps <= k {
                    break;
                }

                total -= fruits[left][1];
                left += 1;
            }

            max_fruits = max_fruits.max(total);
        }

        max_fruits
    }
}
