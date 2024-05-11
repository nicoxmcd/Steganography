function extracted_watermark = extract_watermark(watermarked_image_path, key)
    % Read the watermarked image
    watermarked_img = imread("watermarkedMSB_image.png");
    
    % Extract the MSB from the watermarked image where the watermark was embedded
    msb = bitget(watermarked_img(:,:,1), 8);
    
    % Decrypt the watermark using the same XOR operation as used in embedding
    decrypted_watermark = xor(msb, 0201);
    
    % Convert the binary data back to an image
    extracted_watermark = uint8(decrypted_watermark * 255);
    
    % Save the extracted watermark
    imwrite(extracted_watermark, 'extracted_watermarkMSB.png');
end
