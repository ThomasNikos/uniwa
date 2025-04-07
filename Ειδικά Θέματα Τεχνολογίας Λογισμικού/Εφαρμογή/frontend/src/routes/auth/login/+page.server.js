import { fail } from '@sveltejs/kit';
/** @satisfies {import('./$types').Actions} */
export const actions = {
    default: async ({ request }) => {
        const data = await request.formData();
        const username = data.get('username');
        const password = data.get('password');

        try {
            const response = await fetch('http://localhost:3000/api/login', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    username,
                    password
                }),
            });

            if (!response.ok) {
                const errorData = await response.json();
                console.log(errorData)
                return fail(400, {
                    success: false,
                    message : errorData 
                });
            }
            
            const responseData = await response.json();

            
            return { 
                success: true, 
                user: responseData.user,
                token:responseData.token
            };
        } catch (error) {
            console.error('Error during login:', error);
            return { error: 'Something went wrong' };
        }
    }
};
