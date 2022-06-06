#include <string>
#include <boost/gil/extension/dynamic_image/any_image.hpp>

namespace bg = boost::gil;

class ImageManipulator {
    public:
      std::string image_fpath;

      ImageManipulator(std::string);
      void resize_image(int, int);
      void crop_image();
    private:
      bg::any_image<bg::gray8_image_t, bg::rgb8_image_t, bg::gray16_image_t, bg::rgb16_image_t> usr_input_img;

};
