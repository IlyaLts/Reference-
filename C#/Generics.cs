/*
C# allows you to define generic classes, interfaces, abstract classes, fields, methods,
static methods, properties, events, delegates, and operators using the type parameter and
without the specific data type. A type parameter is a placeholder for a particular type
specified when creating an instance of the generic type.
*/

class DataStore<T>
{
    public T Data { get; set; }
}

class KeyValuePair<TKey, TValue>
{
    public TKey Key { get; set; }
    public TValue Value { get; set; }
}