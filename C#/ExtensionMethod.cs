/*
===================
	Without
===================
*/
public static class ScottGuExtensions
{
    public static bool IsValidEmailAddress(string s)
    {
        Regex regex = new Regex(@"^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$");
        return regex.IsMatch(s);
    }
}

/*
===================
	Example
===================
*/
string email = Request.QueryString["email"];

if ( EmailValidator.IsValid(email) ) {
   
}

/*
===================
	With
===================
*/
public static class ScottGuExtensions
{
    public static bool IsValidEmailAddress(this string s)
    {
        Regex regex = new Regex(@"^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$");
        return regex.IsMatch(s);
    }
}

/*
===================
	Example
===================
*/
string email = Request.QueryString["email"];

if ( email.IsValidEmailAddress() ) {
   
}