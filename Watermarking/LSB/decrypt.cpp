#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function to extract the hidden image from the carrier
Mat extractImage(const Mat &carrier, int width, int height) {
    Mat extracted(Size(width, height), CV_8UC1);

    // Extracting the LSB of each pixel
    for (int i = 0; i < carrier.rows; i++) {
        for (int j = 0; j < carrier.cols; j++) {
            extracted.at<uchar>(i, j) = (carrier.at<uchar>(i, j) & 0x01) << 7;
        }
    }

    return extracted;
}

int main() {
    Mat carrier = imread("LSB_encrypted.jpg", IMREAD_GRAYSCALE);

    if (carrier.empty()) {
        cout << "Error loading image, check file and path name again!" << endl;
        return -1;
    }

    // Optionally, extract the image to verify
    Mat extracted = extractImage(carrier, carrier.cols, carrier.rows);
    imwrite("LSB_extracted_image.jpg", extracted);

    cout << "LSB decryption completed!" << endl;
    return 0;
}

