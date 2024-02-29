#ifndef SIMDUTF_RVV_IMPLEMENTATION_H
#define SIMDUTF_RVV_IMPLEMENTATION_H

#include "simdutf.h"
#include "simdutf/internal/isadetection.h"

namespace simdutf {
namespace rvv {

namespace {
using namespace simdutf;
} // namespace

class implementation final : public simdutf::implementation {
public:
  simdutf_really_inline implementation()
      : simdutf::implementation("rvv", "RISC-V Vector Extension",
                                 internal::instruction_set::RVV)
      , _supports_zvbb(
#if SIMDUTF_IS_ZVBB
          internal::detect_supported_architectures() & internal::instruction_set::ZVBB
#else
          false
#endif
        )
  {}
  simdutf_warn_unused int detect_encodings(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused result validate_utf8_with_errors(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused result validate_ascii_with_errors(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16le(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16be(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused result validate_utf16le_with_errors(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused result validate_utf16be_with_errors(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf32(const char32_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused result validate_utf32_with_errors(const char32_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused size_t convert_latin1_to_utf8(const char *buf, size_t len, char *utf8_output) const noexcept final;
  simdutf_warn_unused size_t convert_latin1_to_utf16le(const char *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_latin1_to_utf16be(const char *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_latin1_to_utf32(const char *buf, size_t len, char32_t *utf32_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_latin1(const char *buf, size_t len, char *latin1_output) const noexcept final;
  simdutf_warn_unused result convert_utf8_to_latin1_with_errors(const char *buf, size_t len, char *latin1_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_latin1(const char *buf, size_t len, char *latin1_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char *buf, size_t len, char16_t *utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char *buf, size_t len, char16_t *utf16_output) const noexcept final;
  simdutf_warn_unused result convert_utf8_to_utf16le_with_errors(const char *buf, size_t len, char16_t *utf16_output) const noexcept final;
  simdutf_warn_unused result convert_utf8_to_utf16be_with_errors(const char *buf, size_t len, char16_t *utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf32(const char *buf, size_t len, char32_t *utf32_output) const noexcept final;
  simdutf_warn_unused result convert_utf8_to_utf32_with_errors(const char *buf, size_t len, char32_t *utf32_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char *buf, size_t len, char32_t *utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_latin1(const char16_t *buf, size_t len, char *latin1_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_latin1(const char16_t *buf, size_t len, char *latin1_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf16le_to_latin1_with_errors(const char16_t *buf, size_t len, char *latin1_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf16be_to_latin1_with_errors(const char16_t *buf, size_t len, char *latin1_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_latin1(const char16_t *buf, size_t len, char *latin1_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_latin1(const char16_t *buf, size_t len, char *latin1_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf16le_to_utf8_with_errors(const char16_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf16be_to_utf8_with_errors(const char16_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf32_to_utf8_with_errors(const char32_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t *buf, size_t len, char *utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_latin1(const char32_t *buf, size_t len, char *latin1_output) const noexcept final;
  simdutf_warn_unused result convert_utf32_to_latin1_with_errors(const char32_t *buf, size_t len, char *latin1_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_latin1(const char32_t *buf, size_t len, char *latin1_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf32_to_utf16le_with_errors(const char32_t *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf32_to_utf16be_with_errors(const char32_t *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t *buf, size_t len, char16_t *utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t *buf, size_t len, char32_t *utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t *buf, size_t len, char32_t *utf32_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf16le_to_utf32_with_errors(const char16_t *buf, size_t len, char32_t *utf32_buffer) const noexcept final;
  simdutf_warn_unused result convert_utf16be_to_utf32_with_errors(const char16_t *buf, size_t len, char32_t *utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t *buf, size_t len, char32_t *utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t *buf, size_t len, char32_t *utf32_buffer) const noexcept final;
  void change_endianness_utf16(const char16_t *buf, size_t len, char16_t *output) const noexcept final;
  simdutf_warn_unused size_t count_utf16le(const char16_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t count_utf16be(const char16_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t count_utf8(const char *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf8(const char *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf8(const char *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t latin1_length_from_utf8(const char *buf, size_t len) const noexcept;
  simdutf_warn_unused size_t latin1_length_from_utf16(size_t len) const noexcept;
  simdutf_warn_unused size_t latin1_length_from_utf32(size_t len) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_latin1(size_t len) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_latin1(size_t len) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_latin1(const char *buf, size_t len) const noexcept;
private:
  const bool _supports_zvbb;
  bool supports_zvbb() const { return _supports_zvbb; }
};

} // namespace rvv
} // namespace simdutf

#endif // SIMDUTF_RVV_IMPLEMENTATION_H
