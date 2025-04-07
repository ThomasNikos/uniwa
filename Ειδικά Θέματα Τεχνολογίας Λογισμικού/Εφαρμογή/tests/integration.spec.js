// @ts-check
import { test, expect } from "@playwright/test";

test.beforeEach(async ({ page }) => {
  await page.goto('/');
  await page.getByRole("button", { name: "Login" }).click();
  await page.waitForTimeout(500);
  await page.fill('input[name="username"]', "Nikos_test");
  await page.fill('input[name="password"]', "test");
  await page.click('button[type="submit"]');
  await page.waitForTimeout(500);
});

test("Ο χρήστης μπορεί να κλίσει ραντεβού", async ({ page }) => {
  await page.goto('/');
  await page.getByRole('link', { name: 'Κλείσε ραντεβού' }).click();
  await page.waitForTimeout(500);
  await page.getByRole('button', { name: ':45 π.μ.' }).click();
  await page.getByRole('button', { name: 'Επιβεβαίωση Κράτησης' }).click();
  await page.locator('div').filter({ hasText: 'Το ραντεβού καταχωρήθηκε με επιτυχία!' }).nth(1).click();
});

test('Ώρα κρατημένη', async ({ page }) => {
  await page.goto('/');
  await page.getByRole('link', { name: 'Κλείσε ραντεβού' }).click();
  await page.waitForTimeout(500);
  await page.getByRole('button', { name: ':45 π.μ.' }).click();
  await page.getByRole('button', { name: 'Επιβεβαίωση Κράτησης' }).click();
  await page.getByText('Η ώρα δεν είναι διαθέσιμη').click();
});