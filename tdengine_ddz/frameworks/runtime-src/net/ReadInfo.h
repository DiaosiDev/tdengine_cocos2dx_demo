#ifndef _READ_INFO_H_
#define _READ_INFO_H_
#include <stdint.h>

class ReadInfo
{
public:
	ReadInfo();
	~ReadInfo();

	char* buffer;
	int msz; //message�����ڴ��Ĵ�С
	int nprt;//ָ�����ݵĵ�ַ
	int sz;  //buffer������ڴ��С
	int dsz; //���ݿ��ܴ�С

	char* getNextMessage(int& size);
	void appendBuffer(char* value, int size);
	
private:
	char* message;
	int mSkipIndex; //��ȡ��ַ��ƫ����
	static const int defaultSize = 10240;
	static const int headSize = 8;
	inline bool setMessageHead();
	bool setMessageInfo(int length);

	char getBufferIndex(int index);
	void setBufferIndex(int index, char value);
	void costBufferLegnth(int length);
	int getLeftBufferSize();
	void expandBuffer(int size);
};

#endif
