#pragma once

#include "ofMain.h"

extern "C" {
#include "libavcodec/avcodec.h"
}


class StreamInfo
{
	public:
		StreamInfo();

		~StreamInfo();

		void Clear(); // clears current information

		AVCodecID codec;
		bool software;  //force software decoding


		// VIDEO
		int fpsscale; // scale of 1000 and a rate of 29970 will result in 29.97 fps
		int fpsrate;
		int height; // height of the stream reported by the demuxer
		int width; // width of the stream reported by the demuxer
		float aspect; // display aspect as reported by demuxer
		bool vfr; // variable framerate
		bool stills; // there may be odd still frames in video
		int level; // encoder level of the stream reported by the decoder. used to qualify hw decoders.
		int profile; // encoder profile of the stream reported by the decoder. used to qualify hw decoders.
		bool ptsinvalid;  // pts cannot be trusted (avi's).
		int nb_frames;
        int gop_size;
		int64_t duration;
        int fps;
		// AUDIO
		int channels;
		int samplerate;
		int bitrate;
		int blockalign;
		int bitspersample;

		// SUBTITLE
		int identifier;

		// CODEC EXTRADATA
		void*        extradata; // extra data for codec to use
		unsigned int extrasize; // size of extra data
		unsigned int codec_tag; // extra identifier hints for decoding

		/* ac3/dts indof */
		unsigned int framesize;
		uint32_t     syncword;

		string toString();
};
