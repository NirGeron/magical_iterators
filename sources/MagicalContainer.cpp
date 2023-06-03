#include "MagicalContainer.hpp"
#include <cmath>

using namespace std;
using namespace ariel;



bool MagicalContainer::check_if_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= std::sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> MagicalContainer::getElement(){
    return elements;
}

void MagicalContainer::addElement(int e) {
    elements.emplace_back(e);
}

void MagicalContainer::removeElement(int e) {
    elements.erase(std::remove(elements.begin(), elements.end(), e), elements.end());
    for (auto c : elements) {cout << c << endl;}
    cout << endl;
(elements.end())--;
    if (!elements.empty()) {
        int back = elements.back();
        cout << back << endl;
    }
}

int MagicalContainer::size() {
    return elements.size();
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : container(&container), curr_index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : container(&container), curr_index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer* container, int i)
    : container(container), curr_index(i) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : container(&container), curr_index(0)
{sort(&container);}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++curr_index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& it) const {
    return curr_index == it.curr_index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& it) const {
    return curr_index != it.curr_index;
}


void MagicalContainer::AscendingIterator::sort(MagicalContainer* container){
    std::sort( container->elements.begin(), container->elements.end());
    
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& it) const {
    return curr_index > it.curr_index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& it) const {
    return curr_index < it.curr_index;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator<<(int pace) {
    int paces_counter = 0;
    unsigned long num;
    while (paces_counter < pace) {
        --curr_index;
        num = static_cast<unsigned long>(curr_index);
        if (container->check_if_prime(container->elements[num]))
            ++paces_counter;
    }
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator>>(int pace) {
    int count = 0;
    unsigned long curr;
    while (count < pace) {
        ++curr_index;
        curr = static_cast<unsigned long>(curr_index);
        if (container->check_if_prime(container->elements[curr]))
            ++count;
    }
    return *this;
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(container, 0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return AscendingIterator(container, container->size());
}


int MagicalContainer::AscendingIterator::operator*() const {
    unsigned long jhg=  static_cast<unsigned long>(curr_index);
    return container->elements[jhg];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(container, 0, 1);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return SideCrossIterator(container, container->size(), 1);
}

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), curr_index(0), direction(1) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer* container, int index, int direction)
    : container(container), curr_index(index), direction(direction) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    curr_index += direction;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& it) const {
    return curr_index == it.curr_index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& it) const {
    return curr_index != it.curr_index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& it) const {
    return curr_index > it.curr_index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& it) const {
    return curr_index < it.curr_index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& it) const {
    return curr_index > it.curr_index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& it) const {
    return curr_index < it.curr_index;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator<<(int paces) {
    curr_index -= paces;
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator>>(int paces) {
    curr_index += paces;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator<<(int paces) {
    curr_index -= paces * direction;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator>>(int paces) {
    curr_index += paces * direction;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    unsigned long jhg=  static_cast<unsigned long>(curr_index);
    return container->elements[jhg];
}

MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), curr_index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer* container, int index)
    : container(container), curr_index(index) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    unsigned long jhg;
    do {
        ++curr_index;
        jhg=  static_cast<unsigned long>(curr_index);
    } while (curr_index < container->size() && !container->check_if_prime(container->elements[jhg]));
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& it) const {
    return curr_index == it.curr_index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& it) const {
    return curr_index != it.curr_index;
}

int MagicalContainer::PrimeIterator::operator*() const {
    unsigned long mul=  static_cast<unsigned long>(curr_index);
    return container->elements[mul];
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(container, 0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return PrimeIterator(container, container->size());
}