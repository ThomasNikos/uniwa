public class Person {
	
	private String lastName;
	private String firstName;
	
	public static final String UNKNOWN_VALUE = "noname";
	
	public Person() {
		this.lastName = UNKNOWN_VALUE;
		this.firstName = UNKNOWN_VALUE;
	}
	
	public Person(String lastName) {
		this.lastName = lastName;
		this.firstName = UNKNOWN_VALUE;
	}
	
	public Person(String lastName, String firstName) {
		this.lastName = lastName;
		this.firstName = firstName;
	}
	
	public void setLastName(String lastName) {
		this.lastName = lastName;		
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;		
	}
	
	public String getLastName() {
		return this.lastName;
	}
	
	public String getFirstName() {
		return this.firstName;
	}
	
	public String toString() {
		return "Last Name: " + this.lastName + 
		"\nFirst Name: " + this.firstName;
	}

}