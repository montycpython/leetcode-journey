double myCache[179][179]; // Cache to memoize recursive calls

double soupServingsHelper(int a, int b){
  if (a <= 0 && b <= 0) // Base case: A and B are both empty
    return 0.5;
  else if (a <= 0) // Base case: A is empty
    return 1;
  else if (b <= 0) // Base case: B is empty
    return 0;
  else if (myCache[a][b] != 0) // Check if item is cached
    return myCache[a][b]; // Retrieve from cache
  else{
    double output1 = soupServingsHelper(a - 4, b);
    double output2 = soupServingsHelper(a - 3, b - 1);
    double output3 = soupServingsHelper(a - 2, b - 2);
    double output4 = soupServingsHelper(a - 1, b - 3);
    if (a >= 4) // Cache calculation if A is not empty
      myCache[a - 4][b] = output1;
    if (a >= 3 && b >= 1) // Cache calculation if A, B not empty
      myCache[a - 3][b - 1] = output2;
    if (a >= 2 && b >= 2) // Cache calculation if A, B not empty
      myCache[a - 2][b - 2] = output3;
    if (a >= 1 && b >= 3) // Cache calculation if A, B not empty
      myCache[a - 1][b - 3] = output4;
    return 0.25 * (output1 + output2 + output3 + output4);
  }
}

double soupServings(int n){
  if (n >= 4451) //n asymptotically approaches 1, so return 1 if n is large
    // enough for 1 to be within the threshold of acceptance. This threshold can
    // easily be found by running the program and finding the first output
    // exceeding 0.99999; it happens to be 4451.
    return 1;
  n = (n + 24) / 25; // Divide n by 25, rounding up; optimizes compressed cache
  return soupServingsHelper(n, n);
}
