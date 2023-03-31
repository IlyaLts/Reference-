/*
===============
 Example
===============
*/
using System;
using System.Linq;
using System.Collections.Generic;

static public class Program
{
	// custom linq extension method
	public static IEnumerable<int> Where(this int[] ints, Func<int, bool> exp)
	{
		Console.WriteLine("IEnumerable");
		
		foreach(var n in ints)
			if (exp(n))
				yield return n;
	}
	public static void Main()
	{
		int[] array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		var big = from n in array where n > 5 select n;
		var small = array.Where(n => n < 5).Select(n => n);

		var odd = Enumerable.Select( Enumerable.Where(array, n => n % 2 == 1), n => n);
		
		foreach(var n in big)
			Console.WriteLine(n);
		foreach(var n in small)
			Console.WriteLine(n);
		foreach(var n in odd)
			Console.WriteLine(n);
	}
}
/*
Output:

IEnumerable
6
7
8
9
IEnumerable
1
2
3
4
1
3
5
7
9
*/


// from .. in ..
// let
// where
// orderby .. ascending/descending
// select
// group .. by .. into ..
// join .. in .. on .. equals ..

/*
===============
 from .. in ..
===============
*/
IEnumerable<Country> countryAreaQuery =
    from country in countries
    where country.Area > 500000 //sq km
    select country;
	
/*
===============
 let

Use the let clause to store the result of an expression,
such as a method call, in a new range variable. In the following example,
the range variable firstName stores the first element of the array of strings that is returned by Split.
===============
*/
string[] names = { "Svetlana Omelchenko", "Claire O'Donnell", "Sven Mortensen", "Cesar Garcia" };
IEnumerable<string> queryFirstNames =
    from name in names
    let firstName = name.Split(' ')[0]
    select firstName;

foreach (string s in queryFirstNames)
{
    Console.Write(s + " ");
}

//Output: Svetlana Claire Sven Cesar

/*
===============
 where
 
 Use the where clause to filter out elements from the source data based on one or more predicate expressions.
 The where clause in the following example has one predicate with two conditions.
===============
*/
IEnumerable<City> queryCityPop =
    from city in cities
    where city.Population < 200000 && city.Population > 100000
    select city;
	
/*
===============
 orderby .. ascending/descending
 
 Use the orderby clause to sort the results in either ascending or descending order.
 You can also specify secondary sort orders. The following example performs a primary sort on
 the country objects by using the Area property. It then performs a secondary sort
 by using the Population property.
===============
*/
IEnumerable<Country> querySortedCountries =
    from country in countries
    orderby country.Area, country.Population descending
    select country;
	
/*
===============
 select
 
 Use the select clause to produce all other types of sequences.
 A simple select clause just produces a sequence of the same type of objects as the objects that
 are contained in the data source.
===============
*/
IEnumerable<Country> sortedQuery =
    from country in countries
    orderby country.Area
    select country;
	
// or 
// Here var is required because the query
// produces an anonymous type.
var queryNameAndPop =
    from country in countries
    select new
    {
        Name = country.Name,
        Pop = country.Population
    };
	
/*
===============
 group .. by .. into ..
 
 Use the group clause to produce a sequence of groups organized by a key that you specify.
 The key can be any data type. For example, the following query creates a sequence of groups that
 contains one or more Country objects and whose key is a char type with value being the first letter of
 countries' names.
===============
*/
var queryCountryGroups =
    from country in countries
    group country by country.Name[0];

//===========
// with into
//===========
// percentileQuery is an IEnumerable<IGrouping<int, Country>>
var percentileQuery =
    from country in countries
    let percentile = (int)country.Population / 10_000_000
    group country by percentile into countryGroup
    where countryGroup.Key >= 20
    orderby countryGroup.Key
    select countryGroup;

// grouping is an IGrouping<int, Country>
foreach (var grouping in percentileQuery)
{
    Console.WriteLine(grouping.Key);
    foreach (var country in grouping)
    {
        Console.WriteLine(country.Name + ":" + country.Population);
    }
}

/*
===============
 join .. in .. on .. equals ..
 
 Use the join clause to associate and/or combine elements from one data source with elements
 from another data source based on an equality comparison between specified keys in each element.
 In LINQ, join operations are performed on sequences of objects whose elements are different types.
 After you have joined two sequences, you must use a select or group statement to specify which
 element to store in the output sequence.
===============
*/
var categoryQuery =
    from cat in categories
    join prod in products on cat equals prod.Category
    select new
    {
        Category = cat,
        Name = prod.Name
    };

//=========================================
// EXAMPLES
//=========================================
int highScoreCount = (
    from score in scores
    where score > 80
    select score
).Count();

// or 
IEnumerable<int> highScoresQuery3 =
    from score in scores
    where score > 80
    select score;

int scoreCount = highScoresQuery3.Count();

// or
IEnumerable<int> highScoresQuery =
    from score in scores
    where score > 80
    orderby score descending
    select score;
	
/*
============================================================================================================
Query variable
============================================================================================================
*/
// Data source.
int[] scores = { 90, 71, 82, 93, 75, 82 };

// Query Expression.
IEnumerable<int> scoreQuery = //query variable
    from score in scores //required
    where score > 80 // optional
    orderby score descending // optional
    select score; //must end with select or group

// Execute the query to produce the results
foreach (int testScore in scoreQuery)
{
    Console.WriteLine(testScore);
}

// Output: 93 90 82 82

/*
============================================================================================================
Join
============================================================================================================
*/
Person magnus = new(FirstName: "Magnus", LastName: "Hedlund");
Person terry = new("Terry", "Adams");
Person charlotte = new("Charlotte", "Weiss");
Person arlene = new("Arlene", "Huff");
Person rui = new("Rui", "Raposo");

List<Person> people = new() { magnus, terry, charlotte, arlene, rui };

List<Pet> pets = new()
{
    new(Name: "Barley", Owner: terry),
    new("Boots", terry),
    new("Whiskers", charlotte),
    new("Blue Moon", rui),
    new("Daisy", magnus),
};

// Create a collection of person-pet pairs. Each element in the collection
// is an anonymous type containing both the person's name and their pet's name.
var query =
    from person in people
    join pet in pets on person equals pet.Owner
    select new
    {
        OwnerName = person.FirstName,
        PetName = pet.Name
    };

foreach (var ownerAndPet in query)
{
    Console.WriteLine($"\"{ownerAndPet.PetName}\" is owned by {ownerAndPet.OwnerName}");
}

/* Output:
     "Daisy" is owned by Magnus
     "Barley" is owned by Terry
     "Boots" is owned by Terry
     "Whiskers" is owned by Charlotte
     "Blue Moon" is owned by Rui
*/