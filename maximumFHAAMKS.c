int maxTotalFruits(int** fruits, int fruitsSize, int* fruitsColSize, int startPos, int k) { //fruits-harvested-after-at-most-k-steps
    int maxFruits = 0;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < fruitsSize; ++right) {
        sum += fruits[right][1];

        while (left <= right) {
            int l = fruits[left][0];
            int r = fruits[right][0];
            int cost;

            if (startPos <= l) {
                cost = r - startPos;
            } else if (startPos >= r) {
                cost = startPos - l;
            } else {
                int leftFirst = 2 * (startPos - l) + (r - startPos);
                int rightFirst = 2 * (r - startPos) + (startPos - l);
                cost = leftFirst < rightFirst ? leftFirst : rightFirst;
            }

            if (cost <= k) break;

            sum -= fruits[left][1];
            left++;
        }

        if (sum > maxFruits) maxFruits = sum;
    }

    return maxFruits;
}
