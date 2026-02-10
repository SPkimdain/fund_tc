using System;
using System.ComponentModel.DataAnnotations;

namespace RSAPadding
{
    class RSACSPSample
    {
        [Required]
        public int ID { get; set; }

        public string Title { get; set; }

        [DataType(DataType.Date)]
        [DisplayFormat(DataFormatString = "{0:yyyy-MM-dd}", ApplyFormatInEditMode = true)]
        public DateTime DateOfEmployment { get; set; }
        
        [Required]
        public string Username { get; set; }

        [Required] // @violation
        public string Password { get; set; }

        [DataType(DataType.Password)]
        public string Password2 { get; set; }

        [Required] // @violation
        public string pw { get; set; }

        [Required] // @violation
        public string ConfirmPassword { get; set; }

        static void Main()
        {

        }
    }
}