impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let num_rows = num_rows as usize;
        let mut triangle: Vec<Vec<i32>> = Vec::with_capacity(num_rows);

        // Buffers for current and previous rows
        let mut prev: Vec<i32> = Vec::new();
        let mut curr: Vec<i32> = Vec::new();

        for i in 0..num_rows {
            curr.clear();
            curr.push(1); // First element is always 1

            for j in 1..i {
                curr.push(prev[j - 1] + prev[j]);
            }

            if i > 0 {
                curr.push(1); // Last element is always 1
            }

            // Push a clone of the current row
            triangle.push(curr.clone());

            // Swap buffers for next iteration
            std::mem::swap(&mut prev, &mut curr);
        }

        triangle
    }
}
