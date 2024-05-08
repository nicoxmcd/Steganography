# Steganography

Steganography involves hiding sensitive or private information within host images or media, making it unnoticeable to the untrained eye. Also, steganalysis aims to detect the hidden message within the media; typically, without knowledge of the steganography method or its parameters. Various methods are utilized depending on the file format, with techniques for BMP files including LSB, QIM, and Spread Spectrum, while JPEG files use methods like Outguess, Steghide, and F5.
Our project successfully encrypts a secret image within the host image and then can also decrypt the concealed image without using the original secret image. Our project will replace the Least Significant Bit (LSB) and or Most Significant Bit (MSB) streams to encrypt an image onto a host image in C++. Additionally, we will also create a decrypting algorithm for the same image, also in C++. For our tools and procedures, we use Visual Studio Code and the Windows Command Terminal to use the scripts.

## Watermarking Background 
Watermarking is a closely related practice where a secret message, only extractable with a specific key, is embedded within a host message. This can be used for asserting authenticity or origin, especially in multimedia like video, audio, and images. Digital watermarks, which can be either visible or invisible, play important roles in applications such as authentication, media bridging, broadcast monitoring, fingerprinting, and secret communications. The effectiveness of a watermark depends on its resilience to attacks, its capacity, and its stealth. 

Watermarking faces various threats, including active attacks aimed at removing or destroying watermarks, passive attacks that seek to detect their presence, collusion attacks that attempt to eliminate watermarks using multiple copies of data, and forgery attacks that involve embedding illegitimate watermarks. Each type of attack poses distinct challenges depending on the watermark's intended application, influencing the requirements for transparency, robustness, recoverability, capacity, and efficiency in watermark encoding and decoding. 

**CLone the Repo**
```
git clone https://github.com/nicomcd/Steganography.git
```

**Directory**
Go to either the LSB or MSB directory to use the program:
```
cd Watermarking/LSB
```
or
```
cd Watermarking/MSB
```

**Compliation**
Replace the file name with the file you are going to use:
```
g++ -o steganography $FileName.cpp `pkg-config --cflags --libs opencv4`
```

**Run**
Replace the path and file name for whichever program you will use:
```
.$FileName
```
