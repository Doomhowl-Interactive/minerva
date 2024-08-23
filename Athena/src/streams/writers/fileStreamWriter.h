#pragma once
#ifndef FILE_STREAM_WRITER
#define FILE_STREAM_WRITER
#include <streams/writers/streamWriter.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <util/buffer.h>
namespace athena
{
	class fileStreamWriter : public streamWriter
	{
	public:
		fileStreamWriter(std::filesystem::path& path);
		fileStreamWriter(const fileStreamWriter&) = delete;
		~fileStreamWriter();
		virtual bool isStreamGood() const;
		virtual void setStreamPosition(size_t index);
		virtual void previousStreamSection();
		virtual void nextStreamSection();
		virtual size_t getStreamSectionCount() const;
		virtual void writeData(const char* data, size_t size);
		template<typename T>
		void writeObject(const T& object) { sections[sectionIndex].writeObject(object) };
		template<typename T>
		void writeArray(const std::vector<T>& vector) { sections[sectionIndex].writeArray(vector); };
		void flush();
	private:
		size_t sectionIndex = 0;

		std::filesystem::path m_path;
		std::ofstream m_stream;
		std::vector<buffer> sections;
	};
}
#endif // !FILE_STREAM_WRITER




