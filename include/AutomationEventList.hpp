#ifndef RAYLIB_CPP_INCLUDE_AUTOMATIONEVENTLIST_HPP_
#define RAYLIB_CPP_INCLUDE_AUTOMATIONEVENTLIST_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * AutomationEventList management functions
 */
class AutomationEventList : public ::AutomationEventList {
 public:
    AutomationEventList(const ::AutomationEventList& automationEventList) {
        set(automationEventList);
    }

    AutomationEventList(unsigned int capacity = 16384,
            unsigned int count = 0,
            AutomationEvent *events = nullptr) : ::AutomationEventList{capacity, count, events} {
        // Nothing.
    }

    AutomationEventList(const char* fileName) {
        Load(fileName);
    }

    AutomationEventList(const AutomationEventList&) = delete;

    AutomationEventList(AutomationEventList&& other) {
        set(other);

        other.capacity = 0;
        other.count = 0;
        other.events = nullptr;
    }

    ~AutomationEventList() {
        Unload();
    }

    GETTERSETTER(unsigned int, Capacity, capacity)
    GETTERSETTER(unsigned int, Count, count)
    GETTERSETTER(AutomationEvent*, Events, events)

    AutomationEventList& operator=(const ::AutomationEventList& other) {
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
     * Load audio stream (to stream raw audio pcm data)
     *
     * @throws raylib::RaylibException Throws if the AutomationEventList failed to load.
     */
    void Load(const char* fileName) {
        Unload();
        set(::LoadAutomationEventList(fileName));
        if (!IsReady()) {
            throw RaylibException("Failed to load automation event list");
        }
    }

    /**
     * Update audio stream buffers with data
     */
    inline AutomationEventList& Unload() {
        ::UnloadAutomationEventList(this);
        return *this;
    }

    inline bool IsReady() {
        return events != nullptr;
    }

    inline bool Export(const char* fileName) {
        return ::ExportAutomationEventList(*this, fileName);
    }

    inline void Set() {
        ::SetAutomationEventList(this);
    }

    inline void SetBaseFrame(int frame) {
        Set();
        ::SetAutomationEventBaseFrame(frame);
    }

    inline void StartRecording() {
        Set();
        ::StartAutomationEventRecording();
    }

    inline void StopRecording() {
        Set();
        ::StopAutomationEventRecording();
    }

    inline void Play() {
        Set();
        ::PlayAutomationEventRecording();
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
