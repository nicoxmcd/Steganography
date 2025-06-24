# Steganography

Steganography involves hiding sensitive or private information within host images or media, making it unnoticeable to the untrained eye. Also, steganalysis aims to detect the hidden message within the media; typically, without knowledge of the steganography method or its parameters. Various methods are utilized depending on the file format, with techniques for BMP files including LSB, QIM, and Spread Spectrum, while JPEG files use methods like Outguess, Steghide, and F5.
Our project successfully encrypts a secret image within the host image and then can also decrypt the concealed image without using the original secret image. Our project will replace the Least Significant Bit (LSB) and or Most Significant Bit (MSB) streams to encrypt an image onto a host image in MATLAB. Additionally, we will also create a decrypting algorithm for the same image, also in MATLAB. For our tools and procedures, we use Visual Studio Code and the Windows Command Terminal to use the scripts. Later, we want to use the opencv and C++ to complete the same task. 

## Watermarking Background 
Watermarking is a closely related practice where a secret message, only extractable with a specific key, is embedded within a host message. This can be used for asserting authenticity or origin, especially in multimedia like video, audio, and images. Digital watermarks, which can be either visible or invisible, play important roles in applications such as authentication, media bridging, broadcast monitoring, fingerprinting, and secret communications. The effectiveness of a watermark depends on its resilience to attacks, its capacity, and its stealth. 

Watermarking faces various threats, including active attacks aimed at removing or destroying watermarks, passive attacks that seek to detect their presence, collusion attacks that attempt to eliminate watermarks using multiple copies of data, and forgery attacks that involve embedding illegitimate watermarks. Each type of attack poses distinct challenges depending on the watermark's intended application, influencing the requirements for transparency, robustness, recoverability, capacity, and efficiency in watermark encoding and decoding. 

## Tutorial for MATLAB Watermarking 
To test these codes, the user must download following all four MATLAB files and two source images into the same folder. Each file is titled to distinguish whether the code is for encryption or decryption by different methods. Users must run encrypting code before they run decrypting code. When the user runs the encrypting code after opening the file, the output watermarked image will be automatically saved into the folder. Then, users can run decrypting codes to test whether the watermark was successfully encrypted or not. The result will also be saved into the folder automatically. 

## Demonstration
Our project was to demonstrate the difference between using a least significant bit (LSB) watermarking technique and a most significant bit (MSB) watermarking technique. Our project successfully shows the reader the reason why we use LSB, because it is undetectable to the eye.
### Encryption Input
**Host Image**
![duck](https://github.com/nicomcd/Steganography/assets/123031251/86e0280c-0384-4df9-a234-c6a248e91579)
**Watermark**
![stevens](https://github.com/nicomcd/Steganography/assets/123031251/67d461ff-d60e-4654-b6bb-5da8e758284e)

### Least Significant Bit Technique
**Watermarked Image**
![watermarkedLSB_image](https://github.com/nicomcd/Steganography/assets/123031251/7333ae5e-00f0-4d09-a9ca-f49a3d9834c3)
**Decrypted Watermark**
![extractedLSB_watermark](https://github.com/nicomcd/Steganography/assets/123031251/5dfa0d70-f1c1-4d77-9b24-fe95f58027e6)

### Most Significant Bit Technique
**Watermarked Image**
![watermarkedMSB_image](https://github.com/nicomcd/Steganography/assets/123031251/97cffaab-8683-409c-a3cc-bfc58a8ef82a)
**Decrypted Watermark**
![extracted_watermarkMSB](https://github.com/nicomcd/Steganography/assets/123031251/36ce5e68-2e96-4b6f-82c2-d85f4ea48897)
