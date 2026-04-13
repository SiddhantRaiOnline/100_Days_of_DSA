void dfs(int** image, int m, int n, int r, int c, int origColor, int newColor) {
    // Boundary + condition check
    if (r < 0 || c < 0 || r >= m || c >= n || image[r][c] != origColor)
        return;

    // Change color
    image[r][c] = newColor;

    // 4 directions
    dfs(image, m, n, r+1, c, origColor, newColor);
    dfs(image, m, n, r-1, c, origColor, newColor);
    dfs(image, m, n, r, c+1, origColor, newColor);
    dfs(image, m, n, r, c-1, origColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
    int origColor = image[sr][sc];

    // Edge case
    if (origColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, imageSize, imageColSize[0], sr, sc, origColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}