#pragma once

#include <stdexcept>

template <template<typename, typename> class Container, typename T>
class LabeledContainer {
private:
    Container<std::pair<std::string, Container<T, std::allocator<T> > >, 
              std::allocator<std::pair<std::string, Container<T, std::allocator<T> > > > > _data;

public:
    typedef typename Container<T, std::allocator<T> >::iterator ContainerIterator;
    typedef typename Container<std::pair<std::string, Container<T, std::allocator<T> > >, 
                              std::allocator<std::pair<std::string, Container<T, std::allocator<T> > > > >::iterator DataIterator;

	/**
	 *  @brief Add a container with a label
	 */
    void addContainer(const std::string& label, const Container<T, std::allocator<T> >& container) {
        _data.push_back(std::make_pair(label, container));
    }

    /**
	 *  @brief Find a container by its label
	 */
    Container<T, std::allocator<T> >* findContainer(const std::string& label) {
        for (DataIterator it = _data.begin(); it != _data.end(); ++it) {
            if (it->first == label) {
                return &(it->second);
            }
        }
        return NULL;
    }

    /**
	 *  @brief Access a container by its index
	 */
    std::pair<std::string, Container<T, std::allocator<T> > >& operator[](size_t index) {
        if (index >= _data.size()) {
            throw std::out_of_range("Index out of range");
        }
        DataIterator it = _data.begin();
        std::advance(it, index);
        return *it;
    }

    size_t size() const {
        return _data.size();
    }
};