#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gray;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gray = (int) ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0 + 0.5);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float _sepiaRed;
    float _sepiaGreen;
    float _sepiaBlue;
    float mid;
    BYTE originalRed;
    BYTE originalGreen;
    BYTE originalBlue;
    BYTE sepiaRed;
    BYTE sepiaGreen;
    BYTE sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;
            _sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            _sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            _sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            if (_sepiaRed > 255)
                _sepiaRed = 255;
            if (_sepiaGreen > 255)
                _sepiaGreen = 255;
            if (_sepiaBlue > 255)
                _sepiaBlue = 255;
            mid = _sepiaRed - (int) _sepiaRed;
            if (mid < 0.5)
            {
                sepiaRed = _sepiaRed;
            }
            else
            {
                sepiaRed = _sepiaRed + 1;
            }
            mid = _sepiaGreen - (int) _sepiaGreen;
            if (mid < 0.5)
            {
                sepiaGreen = _sepiaGreen;
            }
            else
            {
                sepiaGreen = _sepiaGreen + 1;
            }
            mid = _sepiaBlue - (int) _sepiaBlue;
            if (mid < 0.5)
            {
                sepiaBlue = _sepiaBlue;
            }
            else
            {
                sepiaBlue = _sepiaBlue + 1;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int m = width - 1;
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][m - j];
            image[i][m - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    BYTE upRed, upGreen, upBlue;
    BYTE downRed, downGreen, downBlue;
    BYTE leftRed, leftGreen, leftBlue;
    BYTE rightRed, rightGreen, rightBlue;
    BYTE upLeftRed, upLeftGreen, upLeftBlue;
    BYTE upRightRed, upRightGreen, upRightBlue;
    BYTE downLeftRed, downLeftGreen, downLeftBlue;
    BYTE downRightRed, downRightGreen, downRightBlue;
    BYTE originalRed;
    BYTE originalGreen;
    BYTE originalBlue;
    float blurRed;
    float blurGreen;
    float blurBlue;
    BYTE Red;
    BYTE Blue;
    BYTE Green;
    int up, down, left, right;
    float count = 9.0;
    float mid = 0.0;
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            up = i - 1;
            down = i + 1;
            left = j - 1;
            right = j + 1;

            upRed = image[up][j].rgbtRed;
            upGreen = image[up][j].rgbtGreen;
            upBlue = image[up][j].rgbtBlue;
            downRed = image[down][j].rgbtRed;
            downGreen = image[down][j].rgbtGreen;
            downBlue = image[down][j].rgbtBlue;
            leftRed = image[i][left].rgbtRed;
            leftGreen = image[i][left].rgbtGreen;
            leftBlue = image[i][left].rgbtBlue;
            rightRed = image[i][right].rgbtRed;
            rightGreen = image[i][right].rgbtGreen;
            rightBlue = image[i][right].rgbtBlue;
            upLeftRed = image[up][left].rgbtRed;
            upLeftGreen = image[up][left].rgbtGreen;
            upLeftBlue = image[up][left].rgbtBlue;
            upRightRed = image[up][right].rgbtRed;
            upRightGreen = image[up][right].rgbtGreen;
            upRightBlue = image[up][right].rgbtBlue;
            downLeftRed = image[down][left].rgbtRed;
            downLeftGreen = image[down][left].rgbtGreen;
            downLeftBlue = image[down][left].rgbtBlue;
            downRightRed = image[down][right].rgbtRed;
            downRightGreen = image[down][right].rgbtGreen;
            downRightBlue = image[down][right].rgbtBlue;
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            blurRed =
                (upRed + downRed + rightRed + leftRed + upLeftRed + upRightRed + downLeftRed + downRightRed + originalRed) / count;
            blurGreen = (upGreen + downGreen + rightGreen + leftGreen + upLeftGreen + upRightGreen + downLeftGreen +
                         downRightGreen + originalGreen) /
                        count;
            blurBlue = (upBlue + downBlue + rightBlue + leftBlue + upLeftBlue + upRightBlue + downLeftBlue + downRightBlue +
                        originalBlue) /
                       count;

            mid = blurRed - (int) blurRed;
            if (mid >= 0.5)
            {
                Red = blurRed + 1;
            }
            else
            {
                Red = blurRed;
            }
            mid = blurGreen - (int) blurGreen;
            if (mid >= 0.5)
            {
                Green = blurGreen + 1;
            }
            else
            {
                Green = blurGreen;
            }
            mid = blurBlue - (int) blurBlue;
            if (mid >= 0.5)
            {
                Blue = blurBlue + 1;
            }
            else
            {
                Blue = blurBlue;
            }

            temp[i][j].rgbtRed = Red;
            temp[i][j].rgbtGreen = Green;
            temp[i][j].rgbtBlue = Blue;
        }
    }
    count = 6.0;
    for (int j = 1; j < width - 1; j++)
    {
        down = 1;
        left = j - 1;
        right = j + 1;
        downRed = image[down][j].rgbtRed;
        downGreen = image[down][j].rgbtGreen;
        downBlue = image[down][j].rgbtBlue;
        leftRed = image[0][left].rgbtRed;
        leftGreen = image[0][left].rgbtGreen;
        leftBlue = image[0][left].rgbtBlue;
        rightRed = image[0][right].rgbtRed;
        rightGreen = image[0][right].rgbtGreen;
        rightBlue = image[0][right].rgbtBlue;
        downLeftRed = image[down][left].rgbtRed;
        downLeftGreen = image[down][left].rgbtGreen;
        downLeftBlue = image[down][left].rgbtBlue;
        downRightRed = image[down][right].rgbtRed;
        downRightGreen = image[down][right].rgbtGreen;
        downRightBlue = image[down][right].rgbtBlue;
        originalRed = image[0][j].rgbtRed;
        originalGreen = image[0][j].rgbtGreen;
        originalBlue = image[0][j].rgbtBlue;

        blurRed = (downRed + rightRed + leftRed + downLeftRed + downRightRed + originalRed) / count;
        blurGreen = (downGreen + rightGreen + leftGreen + downLeftGreen + downRightGreen + originalGreen) / count;
        blurBlue = (downBlue + rightBlue + leftBlue + downLeftBlue + downRightBlue + originalBlue) / count;

        mid = blurRed - (int) blurRed;
        if (mid >= 0.5)
        {
            Red = blurRed + 1;
        }
        else
        {
            Red = blurRed;
        }
        mid = blurGreen - (int) blurGreen;
        if (mid >= 0.5)
        {
            Green = blurGreen + 1;
        }
        else
        {
            Green = blurGreen;
        }
        mid = blurBlue - (int) blurBlue;
        if (mid >= 0.5)
        {
            Blue = blurBlue + 1;
        }
        else
        {
            Blue = blurBlue;
        }

        temp[0][j].rgbtRed = Red;
        temp[0][j].rgbtGreen = Green;
        temp[0][j].rgbtBlue = Blue;
    }

    for (int j = 1; j < width - 1; j++)
    {
        up = height - 2;
        left = j - 1;
        right = j + 1;

        upRed = image[up][j].rgbtRed;
        upGreen = image[up][j].rgbtGreen;
        upBlue = image[up][j].rgbtBlue;
        leftRed = image[height - 1][left].rgbtRed;
        leftGreen = image[height - 1][left].rgbtGreen;
        leftBlue = image[height - 1][left].rgbtBlue;
        rightRed = image[height - 1][right].rgbtRed;
        rightGreen = image[height - 1][right].rgbtGreen;
        rightBlue = image[height - 1][right].rgbtBlue;
        upLeftRed = image[up][left].rgbtRed;
        upLeftGreen = image[up][left].rgbtGreen;
        upLeftBlue = image[up][left].rgbtBlue;
        upRightRed = image[up][right].rgbtRed;
        upRightGreen = image[up][right].rgbtGreen;
        upRightBlue = image[up][right].rgbtBlue;
        originalRed = image[height - 1][j].rgbtRed;
        originalGreen = image[height - 1][j].rgbtGreen;
        originalBlue = image[height - 1][j].rgbtBlue;

        blurRed = (upRed + rightRed + leftRed + upLeftRed + upRightRed + originalRed) / count;
        blurGreen = (upGreen + rightGreen + leftGreen + upLeftGreen + upRightGreen + originalGreen) / count;
        blurBlue = (upBlue + rightBlue + leftBlue + upLeftBlue + upRightBlue + originalBlue) / count;

        mid = blurRed - (int) blurRed;
        if (mid >= 0.5)
        {
            Red = blurRed + 1;
        }
        else
        {
            Red = blurRed;
        }
        mid = blurGreen - (int) blurGreen;
        if (mid >= 0.5)
        {
            Green = blurGreen + 1;
        }
        else
        {
            Green = blurGreen;
        }
        mid = blurBlue - (int) blurBlue;
        if (mid >= 0.5)
        {
            Blue = blurBlue + 1;
        }
        else
        {
            Blue = blurBlue;
        }

        temp[height - 1][j].rgbtRed = Red;
        temp[height - 1][j].rgbtGreen = Green;
        temp[height - 1][j].rgbtBlue = Blue;
    }

    for (int i = 1; i < height - 1; i++)
    {
        up = i - 1;
        down = i + 1;
        right = 1;

        upRed = image[up][0].rgbtRed;
        upGreen = image[up][0].rgbtGreen;
        upBlue = image[up][0].rgbtBlue;
        downRed = image[down][0].rgbtRed;
        downGreen = image[down][0].rgbtGreen;
        downBlue = image[down][0].rgbtBlue;
        rightRed = image[i][right].rgbtRed;
        rightGreen = image[i][right].rgbtGreen;
        rightBlue = image[i][right].rgbtBlue;
        upRightRed = image[up][right].rgbtRed;
        upRightGreen = image[up][right].rgbtGreen;
        upRightBlue = image[up][right].rgbtBlue;
        downRightRed = image[down][right].rgbtRed;
        downRightGreen = image[down][right].rgbtGreen;
        downRightBlue = image[down][right].rgbtBlue;
        originalRed = image[i][0].rgbtRed;
        originalGreen = image[i][0].rgbtGreen;
        originalBlue = image[i][0].rgbtBlue;

        blurRed = (upRed + downRed + rightRed + upRightRed + downRightRed + originalRed) / count;
        blurGreen = (upGreen + downGreen + rightGreen + upRightGreen + downRightGreen + originalGreen) / count;
        blurBlue = (upBlue + downBlue + rightBlue + upRightBlue + downRightBlue + originalBlue) / count;

        mid = blurRed - (int) blurRed;
        if (mid >= 0.5)
        {
            Red = blurRed + 1;
        }
        else
        {
            Red = blurRed;
        }
        mid = blurGreen - (int) blurGreen;
        if (mid >= 0.5)
        {
            Green = blurGreen + 1;
        }
        else
        {
            Green = blurGreen;
        }
        mid = blurBlue - (int) blurBlue;
        if (mid >= 0.5)
        {
            Blue = blurBlue + 1;
        }
        else
        {
            Blue = blurBlue;
        }

        temp[i][0].rgbtRed = Red;
        temp[i][0].rgbtGreen = Green;
        temp[i][0].rgbtBlue = Blue;
    }

    for (int i = 1; i < height - 1; ++i)
    {
        up = i - 1;
        down = i + 1;
        left = width - 2;

        upRed = image[up][width - 1].rgbtRed;
        upGreen = image[up][width - 1].rgbtGreen;
        upBlue = image[up][width - 1].rgbtBlue;
        downRed = image[down][width - 1].rgbtRed;
        downGreen = image[down][width - 1].rgbtGreen;
        downBlue = image[down][width - 1].rgbtBlue;
        leftRed = image[i][left].rgbtRed;
        leftGreen = image[i][left].rgbtGreen;
        leftBlue = image[i][left].rgbtBlue;
        upLeftRed = image[up][left].rgbtRed;
        upLeftGreen = image[up][left].rgbtGreen;
        upLeftBlue = image[up][left].rgbtBlue;
        downLeftRed = image[down][left].rgbtRed;
        downLeftGreen = image[down][left].rgbtGreen;
        downLeftBlue = image[down][left].rgbtBlue;

        originalRed = image[i][width - 1].rgbtRed;
        originalGreen = image[i][width - 1].rgbtGreen;
        originalBlue = image[i][width - 1].rgbtBlue;

        blurRed = (upRed + downRed + leftRed + upLeftRed + downLeftRed + originalRed) / count;
        blurGreen = (upGreen + downGreen + leftGreen + upLeftGreen + downLeftGreen + originalGreen) / count;
        blurBlue = (upBlue + downBlue + leftBlue + upLeftBlue + downLeftBlue + originalBlue) / count;

        mid = blurRed - (int) blurRed;
        if (mid >= 0.5)
        {
            Red = blurRed + 1;
        }
        else
        {
            Red = blurRed;
        }
        mid = blurGreen - (int) blurGreen;
        if (mid >= 0.5)
        {
            Green = blurGreen + 1;
        }
        else
        {
            Green = blurGreen;
        }
        mid = blurBlue - (int) blurBlue;
        if (mid >= 0.5)
        {
            Blue = blurBlue + 1;
        }
        else
        {
            Blue = blurBlue;
        }

        temp[i][width - 1].rgbtRed = Red;
        temp[i][width - 1].rgbtGreen = Green;
        temp[i][width - 1].rgbtBlue = Blue;
    }

    count = 4.0;
    blurRed = (image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][0].rgbtRed + image[1][1].rgbtRed) / count;
    blurGreen = (image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][0].rgbtGreen + image[1][1].rgbtGreen) / count;
    blurBlue = (image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / count;

    mid = blurRed - (int) blurRed;
    if (mid >= 0.5)
    {
        Red = blurRed + 1;
    }
    else
    {
        Red = blurRed;
    }
    mid = blurGreen - (int) blurGreen;
    if (mid >= 0.5)
    {
        Green = blurGreen + 1;
    }
    else
    {
        Green = blurGreen;
    }
    mid = blurBlue - (int) blurBlue;
    if (mid >= 0.5)
    {
        Blue = blurBlue + 1;
    }
    else
    {
        Blue = blurBlue;
    }

    temp[0][0].rgbtRed = Red;
    temp[0][0].rgbtGreen = Green;
    temp[0][0].rgbtBlue = Blue;

    blurRed =
        (image[0][width - 1].rgbtRed + image[0][width - 2].rgbtRed + image[1][width - 1].rgbtRed + image[1][width - 2].rgbtRed) /
        count;
    blurGreen = (image[0][width - 1].rgbtGreen + image[0][width - 2].rgbtGreen + image[1][width - 1].rgbtGreen +
                 image[1][width - 2].rgbtGreen) /
                count;
    blurBlue = (image[0][width - 1].rgbtBlue + image[0][width - 2].rgbtBlue + image[1][width - 1].rgbtBlue +
                image[1][width - 2].rgbtBlue) /
               count;

    mid = blurRed - (int) blurRed;
    if (mid >= 0.5)
    {
        Red = blurRed + 1;
    }
    else
    {
        Red = blurRed;
    }
    mid = blurGreen - (int) blurGreen;
    if (mid >= 0.5)
    {
        Green = blurGreen + 1;
    }
    else
    {
        Green = blurGreen;
    }
    mid = blurBlue - (int) blurBlue;
    if (mid >= 0.5)
    {
        Blue = blurBlue + 1;
    }
    else
    {
        Blue = blurBlue;
    }

    temp[0][width - 1].rgbtRed = Red;
    temp[0][width - 1].rgbtGreen = Green;
    temp[0][width - 1].rgbtBlue = Blue;

    blurRed = (image[height - 1][0].rgbtRed + image[height - 1][1].rgbtRed + image[height - 2][0].rgbtRed +
               image[height - 2][1].rgbtRed) /
              count;
    blurGreen = (image[height - 1][0].rgbtGreen + image[height - 1][1].rgbtGreen + image[height - 2][0].rgbtGreen +
                 image[height - 2][1].rgbtGreen) /
                count;
    blurBlue = (image[height - 1][0].rgbtBlue + image[height - 1][1].rgbtBlue + image[height - 2][0].rgbtBlue +
                image[height - 2][1].rgbtBlue) /
               count;

    mid = blurRed - (int) blurRed;
    if (mid >= 0.5)
    {
        Red = blurRed + 1;
    }
    else
    {
        Red = blurRed;
    }
    mid = blurGreen - (int) blurGreen;
    if (mid >= 0.5)
    {
        Green = blurGreen + 1;
    }
    else
    {
        Green = blurGreen;
    }
    mid = blurBlue - (int) blurBlue;
    if (mid >= 0.5)
    {
        Blue = blurBlue + 1;
    }
    else
    {
        Blue = blurBlue;
    }

    temp[height - 1][0].rgbtRed = Red;
    temp[height - 1][0].rgbtGreen = Green;
    temp[height - 1][0].rgbtBlue = Blue;

    blurRed = (image[height - 1][width - 1].rgbtRed + image[height - 1][width - 2].rgbtRed + image[height - 2][width - 1].rgbtRed +
               image[height - 2][width - 2].rgbtRed) /
              count;
    blurGreen = (image[height - 1][width - 1].rgbtGreen + image[height - 1][width - 2].rgbtGreen +
                 image[height - 2][width - 1].rgbtGreen + image[height - 2][width - 2].rgbtGreen) /
                count;
    blurBlue = (image[height - 1][width - 1].rgbtBlue + image[height - 1][width - 2].rgbtBlue +
                image[height - 2][width - 1].rgbtBlue + image[height - 2][width - 2].rgbtBlue) /
               count;

    mid = blurRed - (int) blurRed;
    if (mid >= 0.5)
    {
        Red = blurRed + 1;
    }
    else
    {
        Red = blurRed;
    }
    mid = blurGreen - (int) blurGreen;
    if (mid >= 0.5)
    {
        Green = blurGreen + 1;
    }
    else
    {
        Green = blurGreen;
    }
    mid = blurBlue - (int) blurBlue;
    if (mid >= 0.5)
    {
        Blue = blurBlue + 1;
    }
    else
    {
        Blue = blurBlue;
    }

    temp[height - 1][width - 1].rgbtRed = Red;
    temp[height - 1][width - 1].rgbtGreen = Green;
    temp[height - 1][width - 1].rgbtBlue = Blue;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
