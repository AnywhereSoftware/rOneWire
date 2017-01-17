#pragma once
#include "B4RDefines.h"
#include "OneWire.h"
//~version: 1.0
namespace B4R {
	//~shortname: OneWire
	class B4ROneWire {
		private:
			uint8_t beOneWire[sizeof(OneWire)];
			OneWire* oneWire;
		public:
			//Initializes the object. Sets the OneWire pin.
			void Initialize(Byte WirePin);
			/**
			*Searches for the next device. Returns True if a device was found.
			*The order of devices is deterministic.
			*Address - 8 bytes array. The address of the device found will be written to this array.
			*/
			bool Search (ArrayByte* Address);
			//Clears the search state. The next search will start from the beginning.
			void ResetSearch();
			/**
			*Computes a Dallas Semiconductor 16 bit CRC.
			*Data - Array with the bytes to checksum.
			*Length - Number of bytes to use.
			*/
			UInt CRC16 (ArrayByte* Data, UInt Length);
			/**
			*Computes a Dallas Semiconductor 8 bit CRC.
			*Data - Array with the bytes to checksum.
			*Length - Number of bytes to use.
			*/
			Byte CRC8 (ArrayByte* Data, Byte Length);
			//Performs a reset function. Returns True if the device asserted a presence pulse.
			bool Reset();
			//Issues a select command. This is needed after each call to Reset.
			void Select(ArrayByte* Address);
			/**
			*Writes a byte.
			*Value - Value to write.
			*Power - Set to True if power after the write is needed.
			*/
			void Write(Byte Value, bool Power);
			/**
			*Writes bytes.
			*Bytes - Data to write.
			*Power - Set to True if power after the write is needed.
			*/
			void WriteBytes(ArrayByte* Bytes, bool Power);
			/**
			*Reads data.
			*Bytes - Data will be written to this array.
			*Count - Number of bytes to read.
			*/
			void ReadBytes(ArrayByte* Bytes, UInt Count);
			//Skips the device selection. Useful when there is only a single device connected.
			void Skip();
	};
}