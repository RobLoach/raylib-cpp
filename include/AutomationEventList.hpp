#ifndef RAYLIB_CPP_INCLUDE_AUTOMATIONEVENTLIST_HPP_
#define RAYLIB_CPP_INCLUDE_AUTOMATIONEVENTLIST_HPP_

#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * AutomationEventList management functions
 */
class AutomationEventList : public ::AutomationEventList {
 public:
    AutomationEventList(const ::AutomationEventList& automationEventList) : ::AutomationEventList(automationEventList) {
        // Nothing.
    }

    /**
     * Load an empty automation events list.
     */
    AutomationEventList() { set(::LoadAutomationEventList(0)); }

    /**
     * Load automation events list from file.
     *
     * @param fileName The file path to load the automation events list from.
     */
    AutomationEventList(const char* fileName) : ::AutomationEventList{} { Load(fileName); }

    AutomationEventList(const AutomationEventList&) = delete;

    AutomationEventList(AutomationEventList&& other) noexcept {
        set(other);

        other.capacity = 0;
        other.count = 0;
        other.events = nullptr;
    }

    ~AutomationEventList() { Unload(); }

    GETTER(unsigned int, Capacity, capacity)
    GETTER(unsigned int, Count, count)
    GETTER(AutomationEvent*, Events, events)

    AutomationEventList& operator=(const ::AutomationEventList& other) {
        Unload();
        set(other);
        return *this;
    }

    AutomationEventList& operator=(const AutomationEventList&) = delete;

    AutomationEventList& operator=(AutomationEventList&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.capacity = 0;
        other.count = 0;
        other.events = nullptr;

        return *this;
    }

    /**
     * Load automation events list from file, unloading any existing events.
     *
     * @throws raylib::RaylibException Throws if the AutomationEventList failed to load.
     */
    void Load(const char* fileName) {
        Unload();
        set(::LoadAutomationEventList(fileName));
        if (!IsValid()) {
            throw RaylibException("Failed to load automation event list");
        }
    }

    /**
     * Unload automation events list from memory.
     */
    void Unload() {
        if (!IsValid()) {
            return;
        }

        ::UnloadAutomationEventList(*this);
        capacity = 0;
        count = 0;
        events = nullptr;
    }

    /**
     * Check if the automation events list has been loaded.
     */
    bool IsValid() const { return events != nullptr; }

    bool Export(const char* fileName) { return ::ExportAutomationEventList(*this, fileName); }

    void Set() { ::SetAutomationEventList(this); }

    void SetBaseFrame(int frame) {
        Set();
        ::SetAutomationEventBaseFrame(frame);
    }

    void StartRecording() {
        Set();
        ::StartAutomationEventRecording();
    }

    void StopRecording() {
        Set();
        ::StopAutomationEventRecording();
    }

    void Play(int index) {
        if (index < 0 || static_cast<unsigned int>(index) >= this->count) {
            return;
        }

        Set();
        ::PlayAutomationEvent(this->events[index]);
    }

 protected:
    void set(const ::AutomationEventList& other) {
        capacity = other.capacity;
        count = other.count;
        events = other.events;
    }
};
}  // namespace raylib

using RAutomationEventList = raylib::AutomationEventList;

#endif  // RAYLIB_CPP_INCLUDE_AUTOMATIONEVENTLIST_HPP_
