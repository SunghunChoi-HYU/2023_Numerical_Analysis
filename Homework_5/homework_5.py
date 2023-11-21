import cv2

def resize_image(input_path, output_path, target_width, target_height):
    img = cv2.imread(input_path)

    if img is None:
        print(f"이미지를 불러올 수 없습니다: {input_path}")
        return

    resized_img = cv2.resize(img, (target_width, target_height))

    cv2.imwrite(output_path, resized_img)

    print(f"이미지가 성공적으로 크기 조절되었습니다. 저장 경로: {output_path}")

if __name__ == "__main__":
    input_image_path = 'img.jpg'

    output_image_path = 'result.jpg'

    target_width = int(input("원하는 가로 크기를 입력하세요: "))
    target_height = int(input("원하는 세로 크기를 입력하세요: "))

    resize_image(input_image_path, output_image_path, target_width, target_height)
