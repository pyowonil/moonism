#include <assert.h>
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/video.hpp>

#include <functional>

namespace file {
	const std::string video = "";
};
namespace name {
	const std::string main_window = "1";
	const std::string video_trackbar = "2";
};

int main() {
	cv::VideoCapture video;

	// open video
	video.open(file::video);
	assert(video.isOpened());
	const int fps = video.get(CV_CAP_PROP_FPS);

	// create window
	cv::namedWindow(name::main_window, CV_WINDOW_NORMAL);

	// create trackbar
	int video_position = 0;
	using trackbar_action = std::function<void(int)>;
	cv::TrackbarCallback trackbar_callback = [](int pos, void* userdata) {
		(*(trackbar_action*)userdata)(pos);
	};
	trackbar_action video_trackbar = [&video](int pos) {
		video.set(CV_CAP_PROP_POS_FRAMES, pos);
	};
	cv::createTrackbar(name::video_trackbar, name::main_window, &video_position, video.get(CV_CAP_PROP_FRAME_COUNT), trackbar_callback, (void*)&video_trackbar);

	while (true) {
		cv::Mat frame;
		video.read(frame);
		if (frame.empty()) break;
		cv::imshow(name::main_window, frame);

		// sync to trackbar position
		video_position = video.get(CV_CAP_PROP_POS_FRAMES);
		cv::setTrackbarPos(name::video_trackbar, name::main_window, video_position);
		if (cv::waitKey(fps) >= 0) break;
	};

	/*std::cout << "opencv test code:" << std::endl;

	cv::Mat image = cv::imread("0u.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cv::namedWindow("0u", CV_WINDOW_AUTOSIZE);
	cv::resize(image.clone(), image, cv::Size(), 0.125, 0.125);
	cv::imshow("0u", image);
	cv::waitKey();

	std::cout << "done." << std::endl;*/
	return 0;
}