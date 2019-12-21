#include "ffmpegcommon.h"

AVPixelFormat FFmpegCommon::GetCompatiblePixelFormat(const AVPixelFormat &pix_fmt)
{
  AVPixelFormat possible_pix_fmts[] = {
    AV_PIX_FMT_RGBA,
    AV_PIX_FMT_RGBA64,
    AV_PIX_FMT_NONE
  };

  return avcodec_find_best_pix_fmt_of_list(possible_pix_fmts,
                                           pix_fmt,
                                           1,
                                           nullptr);
}

SampleFormat FFmpegCommon::GetNativeSampleFormat(const AVSampleFormat &smp_fmt)
{
  switch (smp_fmt) {
  case AV_SAMPLE_FMT_U8:
    return SAMPLE_FMT_U8;
  case AV_SAMPLE_FMT_S16:
    return SAMPLE_FMT_S16;
  case AV_SAMPLE_FMT_S32:
    return SAMPLE_FMT_S32;
  case AV_SAMPLE_FMT_S64:
    return SAMPLE_FMT_S64;
  case AV_SAMPLE_FMT_FLT:
    return SAMPLE_FMT_FLT;
  case AV_SAMPLE_FMT_DBL:
    return SAMPLE_FMT_DBL;
  case AV_SAMPLE_FMT_U8P :
  case AV_SAMPLE_FMT_S16P:
  case AV_SAMPLE_FMT_S32P:
  case AV_SAMPLE_FMT_S64P:
  case AV_SAMPLE_FMT_FLTP:
  case AV_SAMPLE_FMT_DBLP:
  case AV_SAMPLE_FMT_NONE:
  case AV_SAMPLE_FMT_NB:
    break;
  }

  return SAMPLE_FMT_INVALID;
}

AVSampleFormat FFmpegCommon::GetFFmpegSampleFormat(const SampleFormat &smp_fmt)
{
  switch (smp_fmt) {
  case SAMPLE_FMT_U8:
    return AV_SAMPLE_FMT_U8;
  case SAMPLE_FMT_S16:
    return AV_SAMPLE_FMT_S16;
  case SAMPLE_FMT_S32:
    return AV_SAMPLE_FMT_S32;
  case SAMPLE_FMT_S64:
    return AV_SAMPLE_FMT_S64;
  case SAMPLE_FMT_FLT:
    return AV_SAMPLE_FMT_FLT;
  case SAMPLE_FMT_DBL:
    return AV_SAMPLE_FMT_DBL;
  case SAMPLE_FMT_INVALID:
  case SAMPLE_FMT_COUNT:
    break;
  }

  return AV_SAMPLE_FMT_NONE;
}

AVPixelFormat FFmpegCommon::GetFFmpegPixelFormat(const olive::PixelFormat &pix_fmt)
{
  switch (pix_fmt) {
  case olive::PIX_FMT_RGBA8:
    return AV_PIX_FMT_RGBA;
  case olive::PIX_FMT_RGBA16U:
    return AV_PIX_FMT_RGBA64;
  case olive::PIX_FMT_RGBA16F:
  case olive::PIX_FMT_RGBA32F:
  case olive::PIX_FMT_INVALID:
  case olive::PIX_FMT_COUNT:
    break;
  }

  return AV_PIX_FMT_NONE;
}

olive::PixelFormat FFmpegCommon::GetCompatiblePixelFormat(const olive::PixelFormat &pix_fmt)
{
  switch (pix_fmt) {
  case olive::PIX_FMT_RGBA8:
    return olive::PIX_FMT_RGBA8;
  case olive::PIX_FMT_RGBA16U:
  case olive::PIX_FMT_RGBA16F:
  case olive::PIX_FMT_RGBA32F:
    return olive::PIX_FMT_RGBA16U;
  case olive::PIX_FMT_INVALID:
  case olive::PIX_FMT_COUNT:
    break;
  }

  return olive::PIX_FMT_INVALID;
}
