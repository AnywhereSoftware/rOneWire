#include "B4RDefines.h"
namespace B4R {
	void B4ROneWire::Initialize(Byte pin) {
		oneWire = new (beOneWire) OneWire(pin);
	}
	bool B4ROneWire::Search (ArrayByte* Address) {
		return oneWire->search((Byte*)Address->data);
	}
	void B4ROneWire::ResetSearch() {
		oneWire->reset_search();
	}
	UInt B4ROneWire::CRC16 (ArrayByte* Data, UInt Length) {
		return OneWire::crc16((Byte*)Data->data, Length, 0);
	}
	Byte B4ROneWire::CRC8 (ArrayByte* Data, Byte Length) {
		return OneWire::crc8((Byte*)Data->data, Length);
	}
	bool B4ROneWire::Reset() {
		return oneWire->reset();
	}
	void B4ROneWire::Select(ArrayByte* Address) {
		oneWire->select((Byte*)Address->data);
	}
	void B4ROneWire::Write(Byte Value, bool Power) {
		oneWire->write(Value, Power);
	}
	void B4ROneWire::WriteBytes(ArrayByte* Bytes, bool Power) {
		oneWire->write_bytes((Byte*)Bytes, Bytes->length, Power);
	}
	void B4ROneWire::ReadBytes(ArrayByte* Bytes, UInt Count) {
		oneWire->read_bytes((Byte*)Bytes->data, Count);
	}
	void B4ROneWire::Skip() {
		oneWire->skip();
	}
}