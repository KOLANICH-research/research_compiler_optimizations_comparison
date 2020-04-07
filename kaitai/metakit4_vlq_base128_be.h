#pragma once

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <kaitai/kaitaistruct.h>
#include <stdint.h>
#include <memory>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class metakit4_vlq_base128_be_t : public kaitai::kstruct {

public:
    class red_t;

    metakit4_vlq_base128_be_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, metakit4_vlq_base128_be_t* p__root = nullptr);

private:
    void _read();

public:
    ~metakit4_vlq_base128_be_t();

    class red_t : public kaitai::kstruct {

    public:

        red_t(uint8_t p_idx, kaitai::kstream* p__io, metakit4_vlq_base128_be_t* p__parent = nullptr, metakit4_vlq_base128_be_t* p__root = nullptr);

    private:
        void _read();

    public:
        ~red_t();

    private:
        bool f_value;
        int32_t m_value;

    public:
        int32_t value();

    private:
        bool m_term;
        uint64_t m_chunk;
        uint8_t m_idx;
        metakit4_vlq_base128_be_t* m__root;
        metakit4_vlq_base128_be_t* m__parent;

    public:
        bool term() const { return m_term; }
        uint64_t chunk() const { return m_chunk; }
        uint8_t idx() const { return m_idx; }
        metakit4_vlq_base128_be_t* _root() const { return m__root; }
        metakit4_vlq_base128_be_t* _parent() const { return m__parent; }
    };

private:
    bool f_pos_value;
    int32_t m_pos_value;

public:
    int32_t pos_value();

private:
    bool f_value;
    int32_t m_value;

public:
    int32_t value();

private:
    std::unique_ptr<std::vector<std::unique_ptr<red_t>>> m_reduction;
    metakit4_vlq_base128_be_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::vector<std::unique_ptr<red_t>>* reduction() const { return m_reduction.get(); }
    metakit4_vlq_base128_be_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};
