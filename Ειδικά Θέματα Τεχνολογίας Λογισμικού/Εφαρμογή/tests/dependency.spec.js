const { test, expect } = require('@playwright/test');
const AuthService = require('./services/auth-service');
const BookingService = require('./services/booking-service');

test.beforeEach(async ({ page }) => {
  const authService = new AuthService();
  await authService.login(page, "Nikos_test", "test");
});

test("Book appointment", async ({ page }) => {
  const bookingService = new BookingService(page);
  await bookingService.bookAppointment(':45 π.μ.');
  
  const isBooked = await bookingService.checkBookingConfirmation();
  expect(isBooked).toBeTruthy();
});

test("Cannot book already booked time", async ({ page }) => {
  const bookingService = new BookingService(page);
  await bookingService.bookAppointment(':45 π.μ.');
  
  const unavailableMessage = await page.getByText('Η ώρα δεν είναι διαθέσιμη').isVisible();
  expect(unavailableMessage).toBeTruthy();
});