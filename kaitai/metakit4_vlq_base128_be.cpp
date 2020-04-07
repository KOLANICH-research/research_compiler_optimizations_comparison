// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <memory>
#include "metakit4_vlq_base128_be.h"

metakit4_vlq_base128_be_t::metakit4_vlq_base128_be_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, metakit4_vlq_base128_be_t* /* p__root */) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_reduction = nullptr;
    f_pos_value = false;
    f_value = false;
    _read();
}

void metakit4_vlq_base128_be_t::_read() {
    m_reduction = std::unique_ptr<std::vector<std::unique_ptr<red_t>>>(new std::vector<std::unique_ptr<red_t>>());
    {
        int i = 0;
        red_t* _;
        do {
            _ = new red_t(i, m__io, this, m__root);
            m_reduction->push_back(std::move(std::unique_ptr<red_t>(_)));
            i++;
        } while (!(_->term()));
    }
}

metakit4_vlq_base128_be_t::~metakit4_vlq_base128_be_t() {
}

metakit4_vlq_base128_be_t::red_t::red_t(uint8_t p_idx, kaitai::kstream* p__io, metakit4_vlq_base128_be_t* p__parent, metakit4_vlq_base128_be_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_idx = p_idx;
    f_value = false;
    _read();
}

void metakit4_vlq_base128_be_t::red_t::_read() {
    m_term = m__io->read_bits_int(1);
    m_chunk = m__io->read_bits_int(7);
}

metakit4_vlq_base128_be_t::red_t::~red_t() {
}

int32_t metakit4_vlq_base128_be_t::red_t::value() {
    if (f_value)
        return m_value;
    m_value = (((idx() != 0) ? ((static_cast<uint64_t>(_parent()->reduction()->at((idx() - 1))->value()) << 7)) : (0)) | chunk());
    f_value = true;
    return m_value;
}

int32_t metakit4_vlq_base128_be_t::pos_value() {
    if (f_pos_value)
        return m_pos_value;
    m_pos_value = reduction()->at((reduction()->size() - 1))->value();
    f_pos_value = true;
    return m_pos_value;
}

int32_t metakit4_vlq_base128_be_t::value() {
    if (f_value)
        return m_value;
    m_value = (( ((reduction()->at(0)->term()) || (reduction()->at(0)->chunk() != 0)) ) ? (pos_value()) : (~(pos_value())));
    f_value = true;
    return m_value;
}
