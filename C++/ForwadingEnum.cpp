struct File
{
    enum Type : int; // type (: int) or enum class required for this

    File(){}
    File(QString path, Type type, QDateTime time, bool updated = false) : path(path), date(time), updated(updated), exists(true), type(type){}

    QString path;
    QDateTime date;
    bool updated = false;
    bool exists = false;

    enum Type : int
    {
        none,
        file,
        dir
    } type = none;
};