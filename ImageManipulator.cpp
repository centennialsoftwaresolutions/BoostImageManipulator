#include <ImageManipulator.h>
#include <iostream>
#include <stdexcept>


ImageManipulator::ImageManipulator(std::string image_fpath)
{
    this->image_fpath = image_fpath;
    bg::read_image(this->image_fpath, this->usr_input_img, bg::jpeg_tag{});
}

void ImageManipulator::resize_image(int height, int width)
{
    printf("Resizing image to %dx%d\n", height, width);
    bg::rgb8_image_t resize_square(height, width);
    bg::read_image(image_fpath, this->usr_input_img, bg::jpeg_tag{});
    bg::resize_view(bg::const_view(usr_input_img), bg::view(resize_square), bg::bilinear_sampler());
    bg::write_view("output.jpg", bg::const_view(usr_input_img), bg::jpeg_tag{});
}
void ImageManipulator::crop_image(int top, int left, int height, int width)
{
    bg::rgb8c_view_t cropped_img;
    bg::point_t top_left_point(top, left);
    bg::point_t dimensions(height, width);
    cropped_img = bg::subimage_view(bg::const_view(this->usr_input_img), top_left_point, dimensions);
    bg::write_view("output.jpg", cropped_img, bg::jpeg_tag{});
    return;
}


bool make_user_input_int(std::string& input, int& output) {
    try{
        output = std::stoi(input);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}


template <typename T>
void get_user_info(std::string message, T*t)
{
    std::string user_input_line;
    printf("%s", message.c_str());
    std::cin.clear();
    getline(std::cin, user_input_line);
    while (!make_user_input_int(user_input_line, *t))
    {
        printf("Invalid input - please try again\n");
        getline(std::cin, user_input_line);
    }
}


/* Test the class */
int main(int argc, char *argv[])
{

    std::string user_input_line;

    if (argc < 2)
    {
        printf("Please run this executable with a file path to the image you would like to manipulate as the first argument\n");
        return -1;
    }

    /* Instantiate the image tool with the path to the input file for this session */
    ImageManipulator imgManip((std::string)argv[1]);

    char op = 0;
    while (op != 'q')
    {
        printf("Please select from the menu below : \n");
        printf("1. Resize\n");
        printf("2. Crop\n");
        printf("3. Blur\n");
        printf("press 'q' to exit the program\n");
        printf("Choice : ");
        op = getchar();
        switch (op)
        {
        case '1':
        {
            int height, width;
            get_user_info<int>("Output height : ", &height);
            get_user_info<int>("Output width : ", &width);
            imgManip.resize_image(height, width);
            printf("View results at output.jpg\n");
            break;
        }
        case '2':
        {
            int height, width, left, top;
            get_user_info<int>("leftmost pixel : ", &left);
            get_user_info<int>("topmost pixel : ", &top);
            get_user_info<int>("Output height : ", &height);
            get_user_info<int>("Output width : ", &width);
            imgManip.crop_image(top, left, height, width);
            printf("View results at output.jpg\n");
            printf("case 2\n");
            break;
        }
        case '3':
        {
            printf("case 3\n");
            break;
        }
        case '4':
        {
            printf("case 4\n");
            break;
        }
        case 'q':
        {
            break;
        }
        default:
        {
            printf("Invalid option, please choose again");
            break;
        }
        }
    }

    printf("Program finished...\n");
    return 0;
}
