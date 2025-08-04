func maxTotalFruits(fruits [][]int, startPos int, k int) int { //maximum-fruits-harvested-after-at-most-k-steps
    n := len(fruits)
    maxFruits := 0
    sum := 0
    left := 0

    for right := 0; right < n; right++ {
        sum += fruits[right][1]

        for left <= right {
            leftPos := fruits[left][0]
            rightPos := fruits[right][0]

            // Minimum steps to cover [leftPos, rightPos] from startPos
            steps := min(
                abs(startPos-leftPos)+rightPos-leftPos,
                abs(startPos-rightPos)+rightPos-leftPos,
            )

            if steps <= k {
                break
            }

            sum -= fruits[left][1]
            left++
        }

        maxFruits = max(maxFruits, sum)
    }

    return maxFruits
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
