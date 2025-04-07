class AuthService {
  async login(page, username, password) {
    await page.goto("/");
    await page.getByRole("button", { name: "Login" }).click();
    await page.fill('input[name="username"]', username);
    await page.fill('input[name="password"]', password);
    await page.click('button[type="submit"]');
  }
}

module.exports = AuthService;
