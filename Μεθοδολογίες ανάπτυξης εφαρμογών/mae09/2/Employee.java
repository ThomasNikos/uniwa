public class Employee {
	
	private String name;
	private String potision;
	private int yearHired;
	private double salary;

	public Employee() {
		
	}

	public Employee(String name) {
		this.name = name;		
	}
	
	public  Employee(String name, String potision) {
		this.name = name;			
		this.potision = potision;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getPotision() {
		return this.potision;
	}
	
	public void setPotision(String potision) {
		this.potision = potision;
	}
	
	public int getYearHired() {
		return this.yearHired;
	}
	
	public void setYearHired(int yearHired) {
		this.yearHired = yearHired;
	}

	public double getSalary() {
		return this.salary;
	}
	
	public void setSalary(int salary) {
		this.salary = salary;
	}		

	//Printing can be done in multiple ways.

	public void printEmployeeDetails() {
		System.out.println("Employee name:" + this.getName());
		System.out.println("Employee Salary:" + getSalary());	
		System.out.println("Current potision:" + this.potision);
		System.out.println("Year hired:" + yearHired);
		System.out.println("---------------------");
	}

}

