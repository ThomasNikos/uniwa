class BookingService {
  constructor(page) {
    this.page = page;
  }

  async bookAppointment(time) {
    await this.page.getByRole("link", { name: "Κλείσε ραντεβού" }).click();
    await this.page.getByRole("button", { name: time }).click();
    await this.page
      .getByRole("button", { name: "Επιβεβαίωση Κράτησης" })
      .click();
  }

  async checkBookingConfirmation() {
    return await this.page
      .locator("div", {
        hasText: "Το ραντεβού καταχωρήθηκε με επιτυχία!",
      })
      .isVisible();
  }
}

module.exports = BookingService;
