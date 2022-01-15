#ifndef PARAMETERHANDLER_HPP_
#define PARAMETERHANDLER_HPP_

#include <string>
#include <memory>
#include <fstream>

class ParameterHandler {

    const std::string m_outputImagePath;

    bool m_lcokedAspect;
    float m_aspectRatio;
    uint32_t m_imageWidth ;
    uint32_t m_imageHeight ;

    std::shared_ptr<std::ofstream> m_outputImage;


public:
    enum class ErrorType {
        ERROR_OK,
        ERROR_NOK,
        ERROR_HELP
    };

private:

    void printHelp();

public:

    ParameterHandler(
        uint32_t imageWidth = 400u,
        float aspectRatio = 16.0 / 9.0,
        std::string imagePath = "./image.ppm"
    );

    ~ParameterHandler() = default;

    ParameterHandler(const ParameterHandler &) = delete;
    ParameterHandler& operator=(const ParameterHandler &) = delete;

    ParameterHandler(const ParameterHandler &&) = delete;
    ParameterHandler& operator=(const ParameterHandler &&) = delete;

    std::shared_ptr<std::ofstream> getOutputImage();

    bool setImageWidth(uint32_t width);

    bool setImageHeight(uint32_t height);

    void setImageAspectRatio(float aspecRatio);

    uint32_t getImageWidth() const;

    uint32_t getImageHeight() const;

    float getImageSpectRatio() const;

    void toggleAspectRatioLock(bool toggle);

    bool isAspcetRatioLocked() const;

    ErrorType parseParametrs(uint32_t argc, const char* const argv[]);
};



#endif //PARAMETERHANDLER_HPP_