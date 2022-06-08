#include <ImageManipulator.h>

auto make_user_input_int(std::string input, int& output) {
    try{
        output = std::stoi(input.c_str());
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}


template <typename T>
void get_user_info(std::string message, T*t)
{
    char user_input_line[255];
    printf("%s", message.c_str());
    std::cin.getline(user_input_line, 255);
    while (!make_user_input_int(user_input_line, *t))
    {
        std::cin.getline(user_input_line, 255);
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
                printf("User input image size : %ldx%ld\n", imgManip.get_usr_input_img_width(), imgManip.get_usr_input_img_height());
                get_user_info<int>("Output width : ", &width);
                get_user_info<int>("Output height : ", &height);
                imgManip.resize_image(width, height);
                printf("View results at output.jpg\n");
                break;
            }
            case '2':
            {
                int height, width, left, top;
                printf("User input image size : %ldx%ld\n", imgManip.get_usr_input_img_width(), imgManip.get_usr_input_img_height());
                get_user_info<int>("Leftmost pixel : ", &left);
                get_user_info<int>("Topmost pixel : ", &top);
                get_user_info<int>("Output width : ", &width);
                get_user_info<int>("Output height : ", &height);
                imgManip.crop_image(top, left, width, height);
                printf("View results at output.jpg\n");
                break;
            }
            case '3':
            {
                imgManip.blur_image();
                printf("View results at output.jpg\n");
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
