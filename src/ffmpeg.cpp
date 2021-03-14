#include"ffmpeg.h"

namespace ffmpeg {
	const char* ffmpeg_path = "/ffmpeg/bin";

	/*
	*src_img_pathΪͼƬ�ļ�������Ե�ַ ͼƬ������ʽΪ "img0001.jpg  img0002.jpg"
	 *dst_video_pathΪ������Ƶ��Ե�ַ
	 *img_formatΪͼƬ��ʽ
	 *video_formatΪ��Ƶ��ʽ
	 *fpsΪ��Ƶÿ���֡��
	 */
	void ImgToVideo(const char* src_img_path,
		const char* dst_video_path,
		const char* img_format,
		int fps,
		const char* video_format) 
	{
		char* cmd = (char*)malloc(CMD_MAX_SIZE);
		char* current_path = (char*)malloc(CMD_MAX_SIZE);
		_getcwd(current_path, CMD_MAX_SIZE);
		
		sprintf(cmd,
			"%s/%s/ffmpeg.exe -y -f image2 -i %s/img%%04d.%s -r 25 %s/video.%s",
			current_path,ffmpeg_path,src_img_path,img_format, dst_video_path,video_format);

		system(cmd);
	}

	/*
	*src_video_path: ��Ƶ�ļ���ַ  ��Ƶ�ļ�ͳһ����Ϊ"video.xxx"
	*dst_img_path: ͼƬ�����ļ���ַ
	*video_format: ��Ƶ��ʽ
	*img_format:  ͼƬ��ʽ
	*/
	void VideoToImg(const char* src_video_path,
		const char* dst_img_path,
		const char* video_format,
		const char* img_format)
	{
		char* cmd = (char*)malloc(CMD_MAX_SIZE);
		char* current_path = (char*)malloc(CMD_MAX_SIZE);
		_getcwd(current_path, CMD_MAX_SIZE);
		sprintf(cmd,
			"%s/%s/ffmpeg.exe -i %s/video.%s -r 1 %s/img%%04d.%s",
			current_path, ffmpeg_path, src_video_path, video_format, dst_img_path,img_format);

		system(cmd);
	}

}

