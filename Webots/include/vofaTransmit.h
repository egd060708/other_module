#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

using namespace std;
#define DNUM 14

typedef struct _vofaFrame {
	float fdata[DNUM];
	unsigned char tail[4]{ 0x00, 0x00, 0x80, 0x7f };
}vofaFrame;

class VOFA {
private:
	vofaFrame frame;
	FILE* ffmpeg;
	string process_path;
public:
	VOFA(string _process_path) {
		process_path = _process_path;
		string ffmpeg_command = process_path + string(" -addr localhost:") + string("7299");
		// ���ӽ���
		ffmpeg = _popen(process_path.c_str(), "w");
	}
	~VOFA()
	{
		// �ر��ӽ���
		_pclose(ffmpeg);
	}
	void dataTransmit(float _data[DNUM], int _sleepT)
	{
		memcpy(frame.fdata, _data, sizeof(frame.fdata));
		/* ����fwrite���ӳ���д�ַ��� */
		fwrite(&frame, 1, sizeof(frame), ffmpeg);
		/* ˢ�»��棬������*/
		fflush(ffmpeg);
		// ϵͳ����
		Sleep(abs(_sleepT));
	}
};