# 929. Unique Email Addresses
# easy

class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        unique_emails = set()

        for email in emails:
            # split local and domain
            local, domain = email.split('@')
            # ignore things after '+' in local
            if "+" in local:
                local = local.split("+", 1)[0]
            # delete '.'
            local = local.replace('.', '')
            unique_emails.add(local + "@" + domain)

        return len(unique_emails)
