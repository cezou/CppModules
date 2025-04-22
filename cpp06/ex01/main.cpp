#include "Serializer.hpp"
#include "../Utils.hpp"

int main()
{
	Data data;
	data.value = 16;
	data.text = "SquidGame";
	
	std::cout << "Original Data:" << std::endl;
	data.display();

	uintptr_t serializedData = Serializer::serialize(&data);
	std::cout <<  std::endl << "Serialized Data: " << serializedData << std::endl << std::endl;

	Data *deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized Data:" << std::endl;
	deserializedData->display();
}
