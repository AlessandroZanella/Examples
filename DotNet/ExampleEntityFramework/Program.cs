using System;

namespace ExampleEntityFramework
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var ctx = new DataContext())
            {
                var author1 = new Author()
                {
                    Name =  "Agatha",
                    Surname = "Cristie"
                };
                ctx.Authors.Add(author1);

                var book1 = new Book()
                {
                    Title = "10 piccoli indiani",
                };
                // book1.Authors.Add(author1);
                ctx.Books.Add(book1);

                ctx.SaveChanges();
            }
        }
    }
}
