int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int unplaced = 0;

    for (int i = 0; i < fruitsSize; ++i) {
        int placed = 0;
        for (int j = 0; j < basketsSize; ++j) {
            if (baskets[j] >= 0 && baskets[j] >= fruits[i]) {
                baskets[j] = -1;  // Mark basket as used (negative value)
                placed = 1;
                break;
            }
        }
        if (!placed)
            ++unplaced;
    }

    return unplaced;
}
