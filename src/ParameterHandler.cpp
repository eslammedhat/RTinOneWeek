#include <iostream>
#include <string>

#include "globals.hpp"
#include "ParameterHandler.hpp"

ParameterHandler::ParameterHandler(
    uint32_t imageWidth,
    float aspectRatio,
    std::string imagePath
) :
    m_outputImagePath(imagePath),
    m_lcokedAspect(true),
    m_aspectRatio(aspectRatio),
    m_imageWidth(imageWidth),
    m_imageHeight(static_cast<int>(m_imageWidth / m_aspectRatio)),
    // TODO: this part can throw an exeption wich will prevent the
    //       destructor from being called and freeign the memory.
    //       need to be invistigated.
    m_outputImage(std::make_shared<std::ofstream>())
{

    using std::cout;
    using std::endl;
    // TODO: also should check in case of failure
    m_outputImage->open(m_outputImagePath);
}
//----------------------------------------------------------------
std::shared_ptr<std::ofstream> ParameterHandler::getOutputImage(){
    return m_outputImage;
}
//----------------------------------------------------------------
uint32_t ParameterHandler::getImageWidth() const {
    return m_imageWidth;
}
//----------------------------------------------------------------
uint32_t ParameterHandler::getImageHeight() const {
    return m_imageHeight;
}
//----------------------------------------------------------------
float ParameterHandler::getImageSpectRatio() const {
    return m_aspectRatio;
}
//----------------------------------------------------------------
bool ParameterHandler::setImageWidth(uint32_t width){
    if(m_lcokedAspect){
        return false;
    }
    m_imageWidth = width;
    return true;
}
//----------------------------------------------------------------
bool ParameterHandler::setImageHeight(uint32_t height){
    if(m_lcokedAspect){
        return false;
    }
    m_imageHeight = height;
    return true;
}
//----------------------------------------------------------------
void ParameterHandler::setImageAspectRatio(float aspecRatio){
    m_aspectRatio = aspecRatio;
    if(m_lcokedAspect){
        m_imageHeight = static_cast<int>(m_imageWidth / m_aspectRatio);
    }
}
//----------------------------------------------------------------
void ParameterHandler::toggleAspectRatioLock(bool toggle){
    m_lcokedAspect = toggle;
}
//----------------------------------------------------------------
bool ParameterHandler::isAspcetRatioLocked() const {
    return m_lcokedAspect;
}
//----------------------------------------------------------------
ParameterHandler::ErrorType ParameterHandler::parseParametrs(uint32_t argc, const char* const argv[]) {
    if (argc < 2) {
        return ErrorType::ERROR_OK;
    }

    for (uint32_t arg = 1; arg < argc - 1; arg++) {
        std::string argument(argv[arg]);
        if ((argument == "-h") || (argument == "--help")) {
            printHelp();
            return ErrorType::ERROR_HELP;
        }
        else {
            printHelp();
        }
    }
    return ErrorType::ERROR_NOK;
}
//----------------------------------------------------------------
void ParameterHandler::printHelp() {
    using namespace std;
    cout << PROGRAM_NAME << " \"" << PROGRAM_DESCRIPTION << "\"" << "\n"
        << "Usage: rt [options]" << "\n"
        << "Options:" << "\n"
        << "-h or --help" << "    " << "print help" << endl;
}