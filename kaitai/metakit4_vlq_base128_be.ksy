meta:
  id: metakit4_vlq_base128_be
  title: Metakit 4 variable length integer
seq:
  - id: reduction
    type: red(_index)
    repeat: until
    repeat-until: _.term
instances:
  pos_value:
    value: reduction[reduction.size-1].value
  value:
    value: "(reduction[0].term or reduction[0].chunk != 0)?pos_value:~pos_value"
types:
  red:
    params:
      - id: idx
        type: u1
    seq:
      - id: term
        type: b1
      - id: chunk
        type: b7
    instances:
      value:
        value: "(idx != 0 ? (_parent.reduction[idx-1].value.as<u8> << 7) : 0) | chunk"
