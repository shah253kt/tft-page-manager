#pragma once

template <typename T>
class Property
{
public:
    Property() = default;

    Property(T value)
    {
        set(value);
    }

    ~Property() = default;

    T get() const
    {
        return m_value;
    }

    bool set(T value)
    {
        if (m_value == value)
        {
            return false;
        }

        m_value = value;

        if (valueChanged)
        {
            valueChanged();
        }

        return true;
    }

    void operator=(T value)
    {
        set(value);
    }

    void (*valueChanged)();

private:
    T m_value;
};
