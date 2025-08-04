int totalFruit(int* fruits, int fruitsSize) {
    int max_len = 0;
    int last_fruit = -1, second_last_fruit = -1;
    int last_fruit_count = 0;
    int current_window = 0;

    for (int i = 0; i < fruitsSize; ++i) {
        int fruit = fruits[i];

        if (fruit == last_fruit || fruit == second_last_fruit) {
            current_window++;
        } else {
            current_window = last_fruit_count + 1;
        }

        if (fruit == last_fruit) {
            last_fruit_count++;
        } else {
            last_fruit_count = 1;
            second_last_fruit = last_fruit;
            last_fruit = fruit;
        }

        if (current_window > max_len)
            max_len = current_window;
    }

    return max_len;
}
