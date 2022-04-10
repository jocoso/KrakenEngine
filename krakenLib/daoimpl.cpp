#include "daoimpl.h"

// Marshall
const char* DaoImpl::marshall_chapter(Chapter c) {
	return "nothing";
}

const char* DaoImpl::marshall_person(Person p) {
	return "nothing";
}

const char* DaoImpl::marshall_item(Item i) {
	return "nothing";
}

const char* DaoImpl::marshall_place(Place pl) {
	return "nothing";
}

// Unmarshall
Chapter * DaoImpl::unmarshall_chapter(const char* c) {
	return nullptr;
}

Person * DaoImpl::unmarshall_person(const char* p) {
	return nullptr;
}

Item * DaoImpl::unmarshall_item(const char* i) {
	return nullptr;
}

Place * DaoImpl::unmarshall_place(const char* pl) {
	return nullptr;
}

// Management
void DaoImpl::load(void) {

}

void DaoImpl::write(void) {

}


const unsigned int DaoImpl::add_chapter(Chapter c) {

	c.id = size;
	chapters.insert(c);
	return c.id;

}

Chapter *DaoImpl::get_chapter(const unsigned int id) {

	Chapter ch = chapters.get(id);
	return &ch;

}

Chapter * DaoImpl::remove_chapter(const unsigned int id) {

	return nullptr;

}

void DaoImpl::update_chapter(const unsigned int id) {
	
}

DaoImpl::~DaoImpl() {

}